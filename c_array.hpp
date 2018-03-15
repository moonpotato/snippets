#include <cstddef> // For std::size_t

// The following functions provide a safer way of getting information
// about a C-style array at compile time. Unlike the `sizeof` method,
// these will cause an error if unintentionally passed a pointer.

// The number of elements in a C-style array
template <typename T, std::size_t N>
constexpr std::size_t array_nelems (T(&)[N]) { return N; }

// The size of each element in a C-style array
template <typename T, std::size_t N>
constexpr std::size_t array_elemsz (T(&)[N]) { return sizeof (T); }

// The total size occupied by a C-style array
template <typename T, std::size_t N>
constexpr std::size_t array_size   (T(&)[N]) { return sizeof (T[N]); }
