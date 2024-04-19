# SSTR

## Introduction

The Custom String Library with Fat Pointer is a powerful C-based string manipulation tool designed to provide efficient and flexible string handling capabilities. It leverages the concept of fat pointers for enhanced memory management and offers a comprehensive set of functionalities for creating, manipulating, and managing strings.

## Key Features

### Fat Pointer Implementation

The library uses the concept of fat pointers to efficiently manage string data. Fat pointers store both the pointer to the string data and additional metadata such as length and capacity, allowing for streamlined memory operations.

### String Creation and Manipulation

Users can easily create new strings from C-style strings and perform various string manipulation operations such as appending characters, strings, or other strings. The library provides functions for concatenating strings, finding characters, checking equality, accessing characters at specific indices, and splitting strings based on delimiters.

### Memory Management

Efficient memory management is a core aspect of the library. With the fat pointer implementation, memory allocation and deallocation are optimized for performance and reliability. Users can free memory allocated for strings when no longer needed, ensuring proper resource utilization.

## Usage

The library offers a user-friendly interface with intuitive function names and straightforward usage patterns. Developers can seamlessly integrate the Custom String Library with Fat Pointer into their C projects to handle string-related tasks efficiently and effectively.

## Benefits

- **Efficiency**: Fat pointers enable efficient memory management, reducing overhead and improving performance.
- **Flexibility**: A wide range of string manipulation functions provides flexibility for diverse application requirements.
- **Reliability**: With robust memory management and error handling mechanisms, the library offers reliability in string operations.
- **Simplicity**: The library's intuitive interface and clear documentation make it easy to use for developers of all skill levels.



# sstr API

This is a simple C string API that includes the following functions:

- `sstr_new(const char* cstr)`: creates a new SString object and initializes it with the given C-string.
- `sstr_empty()`: creates a new empty SString object.
- `sstr_len(sstr __a)`: returns the length of the given SString object.
- `sstr_cap(sstr __a)`: returns the capacity of the given SString object.
- `sstr_set_len(sstr __s,size_t len)`: sets the length of the given SString object to the given value.
- `sstr_set_cap(sstr __s,size_t cap)`: sets the capacity of the given SString object to the given value.
- `sstr_free(sstr _a)`: frees the memory used by the given SString object.
- `sstr_reallocate(sstr a)`: reallocates the memory used by the given SString object to fit its contents.
- `sstr_ensure_capacity(sstr a,size_t len)`: ensures that the given SString object has enough capacity to store the given number of characters.
- `sstr_append_char(sstr __s[static 1],char _app)`: appends the given character to the given SString object.
- `sstr_append_str(sstr a[static 1], const char* __a)`: appends the given C-string to the given SString object.
- `sstr_append_sstr(sstr a[static 1],sstr appender)`: appends the given SString object to the given SString object.
- `sstr_cat(sstr a,sstr b)`: concatenates the given SString objects and returns a new SString object containing the result.
- `sstr_find(sstr a,const char delim)`: finds the first occurrence of the given delimiter in the given SString object.
- `sstr_eq(sstr a,sstr b)`: compares the given SString objects for equality.
- `sstr_at(sstr __a, ssize_t sidx)`: returns the character at the given index in the given SString object.
- `sstr_split(sstr __a,const char __delim,size_t* page_len)`: splits the given SString object into an array of SString objects, using the given delimiter as the separator.
- `sstr_freeList(sstr* p,size_t len)`: frees the memory used by the given array of SString objects.

Here is an example of how to use the SString API:

```c
#include <stdio.h>
#include "sstring.h"

int main() {
  // create a new SString object and initialize it with a C-string
  sstr str = sstr_new("Hello, world!");

  // print the length and capacity of the SString object
  printf("Length: %zu, Capacity: %zu\n", sstr_len(str), sstr_cap(str));

  // append a character to the SString object
  sstr_append_char(str, '!');

  // print the updated length and capacity of the SString object
  printf("Length: %zu, Capacity: %zu\n", sstr_len(str), sstr_cap(str));

  // split the SString object into an array of SString objects
  size_t num_parts = 0;
  sstr* parts = sstr_split(str, ' ', &num_parts);

  // print the array of SString objects
  for (size_t i = 0; i < num_parts; i++) {
    printf("Part %zu: %s\n", i, parts[i]);
    sstr_free(parts[i]);
  }
  free(parts);

  // free the memory used by the SString object
  sstr_free(str);

  return 0;
}

```
## Conclusion

The Custom String Library with Fat Pointer empowers C developers with a powerful tool for string manipulation. By leveraging the benefits of fat pointers, the library offers efficiency, flexibility, and reliability in handling string data. Whether for small-scale projects or large-scale applications, the library provides a solid foundation for efficient string management in C programming.
