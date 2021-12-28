/*
 * Copyright (C) 2011-2016 Project SkyFire <http://www.projectskyfire.org/>
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2016 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
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

#ifndef SF_UPDATEMASK_H
#define SF_UPDATEMASK_H

#include "UpdateFields.h"
#include "Errors.h"
#include "ByteBuffer.h"

class UpdateMask
{
public:
    UpdateMask() : _bits(nullptr), _length(0) { }

    ~UpdateMask() { delete[] _bits; }

    void SetBit(uint32 index) { _bits[index] = 1; }
    void UnsetBit(uint32 index) { _bits[index] = 0; }
    uint32* GetBits() const { return _bits; }

    void SetCount(uint32 valuesCount)
    {
        delete[] _bits;

        _bits = new uint32[valuesCount];
        _length = sizeof(uint32) * valuesCount;
        memset(_bits, 0, _length);
    }

    void Clear()
    {
        if (_bits)
            memset(_bits, 0, _length);
    }

private:
    uint32* _bits;
    size_t _length;
};

class UpdateBuilder
{
public:
    UpdateBuilder()
    {
        _mask = new uint32[sizeof(uint32) * (PLAYER_END + 31) / 32];
    }

    ~UpdateBuilder() { delete[] _mask; }

    void SetSource(uint32* src, uint32 count)
    {
        _src = src;
        _blockCount = (count + 31) / 32;
        _length = _blockCount * sizeof(uint32);
        memset(_mask, 0, _length);
    }

    void SetDest(ByteBuffer* dest)
    {
        _dest = dest;
        _start = dest->wpos();
        dest->wpos(_start + 1 + _length);
    }

    bool GetSrcBit(uint32 index) { return _src[index] != 0; }
    void SetDestBit(uint32 index) { ((uint8*)_mask)[index >> 3] |= 1 << (index & 0x7); }

    void Finish()
    {
        size_t endPos = _dest->wpos();
        _dest->wpos(_start);
        *_dest << _blockCount;
        _dest->append((uint8*)_mask, _length);
        _dest->wpos(endPos);
    }

private:
    uint32* _src = nullptr;
    ByteBuffer* _dest = nullptr;
    uint32* _mask;
    size_t _start = 0;
    size_t _end = 0;
    uint8 _blockCount =0 ;
    size_t _length = 0;
};

#endif
