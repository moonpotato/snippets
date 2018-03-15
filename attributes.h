#ifndef ATTRIBUTES_H_INCLUDED
#define ATTRIBUTES_H_INCLUDED

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
# define noreturn [[noreturn]]
#elif defined(STDC_NORETURN)
# define noreturn _Noreturn
#elif defined(CC_MSVC)
# define noreturn __declspec(noreturn)
#elif defined(CC_GNU_COMPAT)
# define noreturn __attribute__((noreturn))
#else
# define noreturn
#endif

#if defined(CXX_DEPRECATED)
# define deprecated(msg) [[deprecated(msg)]]
#elif defined(CC_MSVC)
# define deprecated(msg) __declspec(deprecated(msg))
#elif defined(CC_GNU_COMPAT)
# define deprecated(msg) __attribute__((deprecated(msg)))
#else
# define deprecated(msg)
#endif

#if defined(CXX_UNUSED)
# define unused [[maybe_unused]]
#elif defined(CC_MSVC)
# define unused __pragma(warning(supress: 4100 4101 4102 4189 4505))
#elif defined(CC_GNU_COMPAT)
# define unused __attribute__((unused))
#else
# define unused
#endif

#if defined(CXX_NODISCARD)
# define nodiscard [[nodiscard]]
#elif defined(CC_MSVC)
# define nodiscard _Check_return_
#elif defined(CC_GNU_COMPAT)
# define nodiscard __attribute__((warn_unused_result))
#else
# define nodiscard
#endif

#if defined(CXX_FALLTHROUGH)
# define fallthrough [[fallthrough]]
#elif defined(CC_MSVC)
# define fallthrough _Check_return_
#elif defined(CC_CLANG)
# define fallthrough [[clang::fallthrough]]
#elif defined(CC_GNU_COMPAT)
# if __GNUC__ >= 7
#  define fallthrough __attribute__((fallthrough))
# else
#  define fallthrough
# endif
#else
# define fallthrough
#endif

#if defined(CC_MSVC)
# define noinline __declspec(noinline)
#elif defined(CC_GNU_COMPAT)
# define noinline __attribute__((noinline))
#else
# define noinline
#endif

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
