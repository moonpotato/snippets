# snippets
A collection of useful snippets of C and/or C++ code that might be
reused in other projects.

## Files

### c_array.hpp

Contains C++ template functions for safer operations on C-style
arrays. So far this includes:

- Getting array size, element size and element count.

But you should probably just be using std::array anyway...

### attributes.h

Contains C/C++ macros to define a number of compiler-independent
attributes for a number of purposes, including:

- Marking functions that don't return;
- Warning about functions, variables and types that are deprecated;
- Suppressing compiler warnings about unused variables and types;
- Preventing function return values being ignored;
- Clearly marking switch cases that should fallthrough; and
- Preventing the compiler from inlining functions.
