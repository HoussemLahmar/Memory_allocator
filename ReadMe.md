---

# Simple Memory Allocator

This is a simple memory allocator implementation in C.

## Overview

This memory allocator provides basic implementations of `malloc()`, `free()`, `calloc()`, and `realloc()` functions. It manages memory allocation using a linked list structure and the `sbrk()` system call to manipulate the program break.

## Features

- **Dynamic Memory Allocation**: Allocate and deallocate memory dynamically at runtime.
- **Thread Safety**: Basic locking mechanism ensures thread safety during memory allocation and deallocation.
- **Header Management**: Each allocated memory block is preceded by a header containing metadata such as size and free status.
- **Alignment**: Memory blocks are aligned to 16-byte boundaries for better performance.

## Usage

To use the memory allocator in your project, include the `memallocator.h` header file and link against the `memallocator.c` source file.

Example usage:

```c
#include "memallocator.h"
#include <stdio.h>

int main() {
    // Allocate memory
    int *ptr = (int *)malloc(sizeof(int));
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Use allocated memory
    *ptr = 42;
    printf("Value: %d\n", *ptr);

    // Free allocated memory
    free(ptr);

    return 0;
}
```

## Building

To compile the memory allocator as a shared library, you can use the following command:

```
gcc -o libmemalloc.so -fPIC -shared memallocator.c -pthread
```


---
