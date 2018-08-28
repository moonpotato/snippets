#ifndef KEYWORDS_HPP
#define KEYWORDS_HPP

#include "keywords.h"

// New "keywords" for C++

#define ABSTRACT = 0

#define SELF (*this)

#define RESTRICT __restrict__

#if defined(KW_USE_LOWERCASE)
# define abstract ABSTRACT
# define self     SELF
# define restrict RESTRICT
#endif

#endif
