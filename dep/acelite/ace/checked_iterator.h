// -*- C++ -*-

#ifndef ACE_CHECKED_ITERATOR_H
#define ACE_CHECKED_ITERATOR_H

/**
 * @file checked_iterator.h
 *
 * @brief Checked iterator factory function.
 *
 * Some compilers (e.g. MSVC++ >= 8) issue security related
 * diagnostics if algorithms such as std::copy() are used in an unsafe
 * way.  Normally this isn't an issue if STL container iterators are
 * used in conjuction with the standard algorithms.  However, in cases
 * where application-specific iterators are use with standard
 * algorithms that could potentially overrun a buffer, extra care must
 * be taken to prevent such an overrun.  If supported, checked
 * iterators can be used to address the potential destination buffer
 * overrun.
 *
 * This header provides function templates that generate the
 * appropriate checked iterator.  In cases where checked iterators are
 * not supported, the pointer passed to the function is returned
 * instead.
 *
 * @internal The functions and types in this header are meant for
 *           internal use.  They may change at any point between
 *           releases.
 *
 * @author Ossama Othman
 */

// stdext::checked_array_iterator is a Microsoft extension, not standard C++.
// It was deprecated in VS 2017 15.8 and removed from the MSVC STL altogether,
// so anything built with the VS 2022 toolset or newer fails here with "C2653:
// 'stdext': is not a class or namespace name". ACE predates all of that and
// only ever asked whether the compiler was MSVC, never which version.
//
// Ask for the version too, and let everything from VS 2022 (_MSC_VER 1930) on
// fall through to the plain-pointer branch below. Nothing is lost: the checked
// iterator is a debugging aid that bounds-checks the destination buffer, and
// the fallback is the same one ACE already uses for every non-MSVC compiler.
# if defined (_MSC_VER) && (_MSC_VER < 1930) && (!defined (_STLPORT_VERSION))
#  define ACE_HAS_CHECKED_ARRAY_ITERATOR 1
# endif

# if defined (ACE_HAS_CHECKED_ARRAY_ITERATOR)
// Checked iterators are currently only supported in MSVC++
#  include <iterator>
# endif  /* ACE_HAS_CHECKED_ARRAY_ITERATOR */

# if defined (ACE_HAS_CHECKED_ARRAY_ITERATOR)
template <typename PTR>
stdext::checked_array_iterator<PTR>
ACE_make_checked_array_iterator (PTR buf, size_t len)
{
  return stdext::checked_array_iterator<PTR> (buf, len);
}
# else
template <typename PTR>
PTR
ACE_make_checked_array_iterator (PTR buf, size_t /* len */)
{
  // Checked iterators are unsupported.  Just return the pointer to
  // the buffer itself.
  return buf;
}
# endif  /* ACE_HAS_CHECKED_ARRAY_ITERATOR */

#endif  /* ACE_CHECKED_ITERATOR_H */
