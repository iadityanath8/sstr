# SSTR

The Fat Pointer String Library, abbreviated as SSTR, is a lightweight and efficient library for working with strings in C. It provides a set of functions for creating, manipulating, and managing dynamically allocated strings using a fat pointer representation.

## Features

- Simple interface for string creation and manipulation
- Efficient memory management using fat pointer representation
- Support for operations such as concatenation, duplication, and splitting
- Customizable capacity and allocation strategy

## Functionality

The SSTR library provides the following functions for working with strings:

- builder: Create a string from a character array.
- sstr_len: Get the length of a string.
- sstr_cap: Get the capacity of a string.
- sstr_set_len: Set the length of a string.
- sstr_set_cap: Set the capacity of a string.
- sstr_free: Free the memory allocated for a string.
- sstr_reallocate: Reallocate the memory for a string.
- sstr_append_char: Append a character to a string.
- sstr_append_cstr: Append a C string to a string.
- sstr_cat: Concatenate two strings.
- split: Split a string into an array of strings.
- sstr_dup: Duplicate a string.
- sstr_move: Move ownership of a string.


## Usage

To use the SSTR library in your C project, follow these steps:

1. Include the `sstr.h` header file in your source files:

   ```c
   #include <stdio.h>
    #include "sstr.h"

    int main() {
        // Create a string from a character array
        sstr str = builder("Hello, world!");

        // Print the string length
        printf("Length: %zu\n", sstr_len(str));

        // Free the memory allocated for the string
        sstr_free(str);

        return 0;
    }


## Guidelines

- **Bug Reports**: If you encounter a bug, please ensure it hasn't been reported already. Include steps to reproduce and describe the expected behavior.
- **Feature Requests**: Feel free to suggest new features or improvements. Explain the rationale behind the feature and provide examples if possible.
- **Code Contributions**: Follow the coding style and conventions used in the project. Write clear commit messages and include relevant documentation or tests.
- **Documentation**: Improve existing documentation or add new documentation to clarify usage, features, or contributions.
- **Testing**: Ensure your changes are tested thoroughly. Add new tests if necessary and make sure all existing tests pass.

