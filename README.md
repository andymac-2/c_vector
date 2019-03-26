# c_vector

(C) Andrew Pritchard (Apache 2.0)

For any feature requests, or bugs, please open an issue.

## About

C generics typically use `void *`. Void is type unsafe, and slow. c_vector library aims to provide an implementation of generic vectors in C with type safety using tricky macros.

## Usage

### Quickstart


Copy `gen_vector.h`, `vector.h`, and `vector.c` into your project first.

The c_vector library cannot be simply used as a template. More work is required to use the library. Types should be known and declared ahead of time. Using vectors for undeclared types will result in failed compilation. Types can be declared by modifying `gen_vector.h`. For example, add the following lines to `gen_vector.h` to use the vector library for type `int` and type `float`:

``` C
#define T int
#include "vector.h"
#undef T

#define T float
#include "vector.h"
#undef T
```

The code above exposes the functions of the vector library. The header file to use the vector container is `gen_vector.h`

```C
#include "gen_vector.h"

int main (int argv, char **argc) {
  int_vec vec;
  int_vec_init (&vec);
  
  
  float_vec vec2;
  float_vec_init (&vec2);
  
  /* Do something with the vectors here */
  for (int i = 0 i < 100; i++) {
    float_vec_push(&vec2, i * 30.5);
    int_vec_push(&vec, i + 10);
  }
  
  int_vec_free (&vec);
  float_vec_free (&vec2);
}
```

### API


Available functions are as follows (replace `foo` with any type declared above)

#### `void foo_vec_init (foo_vec* vector)`

Initializes the vector. Call vector initialize before other functions.

#### `void foo_vec_free (foo_vec* vector)`

Deallocates memory requested for the vector. The function is called when the vector is no longer required.

#### `size_t foo_vec_length (foo_vec* vector)`

Returns the (logical) length of the vector.

#### `size_t foo_vec_push (foo_vec* vector, foo elem)`

Push an element onto the end of the vector. On success, returns the new length of the vector. On failure, (insufficient memory) returns 0, and leaves the vector unmodified.

#### `foo foo_vec_pop (foo_vec* vector)`

Removes and return an element from the end of the vector.

#### `void foo_vec_set (foo_vec* vector, size_t index, foo elem)`

Set the element at `index` to `elem`.

#### `foo foo_vec_get (foo_vec* vector, size_t index)`

Returns the element at `index`.

#### `size_t foo_vec_insert ( foo_vec* vector, size_t index, foo elem)`

Inserts a single element at a position given by 'index' and shifts the rest of the elements over by one. Returns the length of the vector on success. Returns `0` and leaves the vector unmodified on failure.

#### `void foo_vec_delete ( foo_vec* vector, size_t index)`

Deletes the element at `index`.

#### `size_t foo_vec_reserve ( foo_vec* vector, size_t psize)`

Reserves enough memory for `psize` elements in the vector, but leaves the vector otherwise unmodified. Function returns the new physical size of the vector. If there is an allocation failure, the old physical size is returned. If the reserved size is shorter than the length of the vector, the vector is shortened accordingly.
