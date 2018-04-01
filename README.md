# snippets
A collection of useful snippets of C and/or C++ code that might be
reused in other projects.

## Files

### Makefile

This isn't a makefile for the snippets project, it's a snippet
itself. This makefile has debug and release modes, and auto-generates
logic ensuring all C++ files are recompiled whenever one of their
dependencies (including header files) changes.

### c_array.hpp

Contains C++ template functions for safer operations on C-style
arrays. So far this includes:

- Getting array size, element size and element count.

But you should probably just be using std::array anyway, at least if
you have C++11 or higher available.

### attributes.h

Contains C/C++ macros to define a number of compiler-independent
attributes for a number of purposes, including:

- Marking functions that don't return;
- Warning about functions, variables and types that are deprecated;
- Suppressing compiler warnings about unused variables and types;
- Preventing function return values being ignored;
- Clearly marking switch cases that should fallthrough; and
- Preventing the compiler from inlining functions.

### keywords.{h,hpp}

Contains some macros for new pseudo-keywords to shorten/increase
meaning of certain common patterns in C/C++.

### enum.hpp

Contains a type-independent way of casting to and from the underlying
integral type of an enum (including a scoped enum).
