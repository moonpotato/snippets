#ifndef ATTRIBUTES_H_INCLUDED
#define ATTRIBUTES_H_INCLUDED

// These macros attempt to provide a more compiler- and standard-
// independent way of accessing some attributes that are common to
// most C/C++ compilers.

// Determine which of the attributes have standard forms in the current
// C or C++ standard being compiled. Save them into macros for later.

#if defined(__cplusplus)
# if (__cplusplus >= 201703L)
#  define CXX_FALLTHROUGH
#  define CXX_NODISCARD
#  define CXX_UNUSED
# endif
# if (__cplusplus >= 201402L)
#  define CXX_DEPRECATED
# endif
# if (__cplusplus >= 201103L)
#  define CXX_NORETURN
#  define CXX_ATTRIBUTES
# endif
#elif defined(__STDC__)
# if (__STDC_VERSION__ >= 201112L)
#  define STDC_NORETURN
# endif
#endif

// Try to determine the compiler manafacturer. Many now claim to be
// __GNUC__, so default to GCC only if no other is recognized.

#if defined(_MSC_VER)
# define CC_MSVC
#elif defined(__GNUC__)
# define CC_GNU_COMPAT
# if defined(__clang__)
#  define CC_CLANG
# elif defined(__INTEL_COMPILER)
#  define CC_INTEL
# else
#  define CC_GCC
# endif
#else
# define CC_UNKNOWN
#endif

#if defined(CXX_NORETURN)
# define NORETURN [[noreturn]]
#elif defined(STDC_NORETURN)
# define NORETURN _Noreturn
#elif defined(CC_MSVC)
# define NORETURN __declspec(noreturn)
#elif defined(CC_GNU_COMPAT)
# define NORETURN __attribute__((noreturn))
#else
# define NORETURN
#endif

#if defined(CXX_DEPRECATED)
# define DEPRECATED(msg) [[deprecated(msg)]]
#elif defined(CC_MSVC)
# define DEPRECATED(msg) __declspec(deprecated(msg))
#elif defined(CC_GNU_COMPAT)
# define DEPRECATED(msg) __attribute__((deprecated(msg)))
#else
# define DEPRECATED(msg)
#endif

#if defined(CXX_UNUSED)
# define UNUSED [[maybe_unused]]
#elif defined(CC_MSVC)
# define UNUSED __pragma(warning(supress: 4100 4101 4102 4189 4505))
#elif defined(CC_GNU_COMPAT)
# define UNUSED __attribute__((unused))
#else
# define UNUSED
#endif

#if defined(CXX_NODISCARD)
# define NODISCARD [[nodiscard]]
#elif defined(CC_MSVC)
# define NODISCARD _Check_return_
#elif defined(CC_GNU_COMPAT)
# define NODISCARD __attribute__((warn_unused_result))
#else
# define NODISCARD
#endif

#if defined(CXX_FALLTHROUGH)
# define FALLTHROUGH [[fallthrough]]
#elif defined(CC_CLANG)
# define FALLTHROUGH [[clang::fallthrough]]
#elif defined(CC_GNU_COMPAT)
# if __GNUC__ >= 7
#  define FALLTHROUGH __attribute__((fallthrough))
# else // Older GCC versions didn't warn, so doesn't matter.
#  define FALLTHROUGH
# endif
#else
# define FALLTHROUGH
#endif

#if defined(CC_MSVC)
# define NOINLINE __declspec(noinline)
#elif defined(CC_GNU_COMPAT)
# define NOINLINE __attribute__((noinline))
#else
# define NOINLINE
#endif

// These lowercase definitions can cause issues with code that wasn't
// expecting them, including headers, so don't define unless
// specifically asked.

#if defined(ATTRIB_USE_LOWERCASE)
# define noreturn        NORETURN
# define deprecated(msg) DEPRECATED(msg)
# define unused          UNUSED
# define nodiscard       NODISCARD
# define fallthrough     FALLTHROUGH
# define noinline        NOINLINE
#endif

// Avoid polluting the global namespace with our internal macros.

#undef CXX_FALLTHROUGH
#undef CXX_NODISCARD
#undef CXX_UNUSED
#undef CXX_DEPRECATED
#undef CXX_NORETURN
#undef CXX_ATTRIBUTES
#undef STDC_NORETURN

#undef CC_MSVC
#undef CC_GNU_COMPAT
#undef CC_CLANG
#undef CC_INTEL
#undef CC_GCC
#undef CC_UNKNOWN

#endif
