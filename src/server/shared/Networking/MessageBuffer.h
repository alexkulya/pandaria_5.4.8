/*
* This file is part of the Pandaria 5.4.8 Project. See THANKS file for Copyright information
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 2 of the License, or (at your
* option) any later version.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
* more details.
*
* You should have received a copy of the GNU General Public License along
* with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef SF_MESSAGEBUFFER_H
#define SF_MESSAGEBUFFER_H

#include "Define.h"

#include <cstring>
#include <vector>

// Replacement for ACE_Message_Block. A flat byte buffer with independent read
// and write cursors, so a socket can append incoming bytes at the write cursor
// while the protocol layer consumes them from the read cursor.
//
// Invariant maintained by every member: _rpos <= _wpos <= _storage.size().
// The region [_rpos, _wpos) is the active data; [_wpos, size()) is free space
// the socket may read into.
class MessageBuffer
{
    typedef std::vector<uint8>::size_type size_type;

public:
    MessageBuffer() : _wpos(0), _rpos(0), _storage(4096) { }

    explicit MessageBuffer(std::size_t initialSize) : _wpos(0), _rpos(0), _storage(initialSize) { }

    MessageBuffer(MessageBuffer const& right) : _wpos(right._wpos), _rpos(right._rpos), _storage(right._storage) { }

    MessageBuffer(MessageBuffer&& right) : _wpos(right._wpos), _rpos(right._rpos), _storage(std::move(right._storage))
    {
        right._wpos = 0;
        right._rpos = 0;
    }

    MessageBuffer& operator=(MessageBuffer const& right)
    {
        if (this != &right)
        {
            _wpos = right._wpos;
            _rpos = right._rpos;
            _storage = right._storage;
        }

        return *this;
    }

    MessageBuffer& operator=(MessageBuffer&& right)
    {
        if (this != &right)
        {
            _wpos = right._wpos;
            _rpos = right._rpos;
            _storage = std::move(right._storage);
            right._wpos = 0;
            right._rpos = 0;
        }

        return *this;
    }

    void Reset()
    {
        _wpos = 0;
        _rpos = 0;
    }

    void Resize(size_type bytes) { _storage.resize(bytes); }

    uint8* GetBasePointer() { return _storage.data(); }

    uint8* GetReadPointer() { return GetBasePointer() + _rpos; }

    uint8* GetWritePointer() { return GetBasePointer() + _wpos; }

    // Bytes written but not yet consumed.
    size_type GetActiveSize() const { return _wpos - _rpos; }

    // Bytes that can still be appended without growing the storage.
    size_type GetRemainingSpace() const { return _storage.size() - _wpos; }

    size_type GetBufferSize() const { return _storage.size(); }

    void ReadCompleted(size_type bytes) { _rpos += bytes; }

    void WriteCompleted(size_type bytes) { _wpos += bytes; }

    // Discard the already consumed prefix by sliding the active data back to
    // the front. Called once a read leaves the write cursor at the end of the
    // storage but part of the buffer has already been handed to the protocol.
    void Normalize()
    {
        if (_rpos)
        {
            if (_rpos != _wpos)
                memmove(GetBasePointer(), GetReadPointer(), GetActiveSize());

            _wpos -= _rpos;
            _rpos = 0;
        }
    }

    // Free space is created by normalizing first; only when the active data
    // already fills the storage does the buffer actually grow. Growing by the
    // current size keeps reallocation amortized.
    void EnsureFreeSpace()
    {
        if (GetRemainingSpace() == 0)
        {
            Normalize();

            if (GetRemainingSpace() == 0)
                _storage.resize(_storage.size() * 2);
        }
    }

    void Write(void const* data, std::size_t size)
    {
        if (size)
        {
            memcpy(GetWritePointer(), data, size);
            WriteCompleted(size);
        }
    }

    std::vector<uint8>&& Move()
    {
        _wpos = 0;
        _rpos = 0;
        return std::move(_storage);
    }

private:
    size_type _wpos;
    size_type _rpos;
    std::vector<uint8> _storage;
};

#endif // SF_MESSAGEBUFFER_H
