#ifndef ENUM_HPP_INCLUDED
#define ENUM_HPP_INCLUDED

#if __cplusplus < 201103L
// This file relies on some template wizardry in the <type_traits>
// header, appearing in C++11 and later.
// TODO: Implement own versions of C++11-only helpers.
#error "C++98 and below is unsupported by " __FILE__
#endif

#include <type_traits>

// The following functions provide a way of accessing the integral,
// underlying type of an enum. This is particularly useful for
// converting scoped enums to and from integral types, which doesn't
// occur automatically.

// Is the underlying integral type of an enum.
template <typename Enum>
using enum_type = typename std::underlying_type<
    typename std::enable_if<
        std::is_enum<Enum>::value, Enum
        >::type
    >::type;

// Cast an enum's value into its underlying type.
template <typename Enum>
constexpr enum_type<Enum> enum_value(Enum val)
{
    return static_cast< enum_type<Enum> >(val);
}

// Get a mutable reference to the same.
template <typename Enum>
constexpr enum_type<Enum>& enum_value(Enum& val)
{
    return static_cast< enum_type<Enum>& >(val);
}

#endif
