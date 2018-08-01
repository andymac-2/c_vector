# c_vector

(C) Andrew Pritchard (Apache 2.0)

For any feature requests, or bugs, please open an issue.

## About

C generics typically use `void *` which is type unsafe, and often slow. This library aims to provide a simple implementation of generic vectors in C with type safety using some tricky macros.

## Usage

### Quickstart

You will need to copy `gen_vector.h`, `vector.h`, and `vector.c` into your project first.

There is a little more work required to use this library than a template in other languages. You must know ahead of time which types you want to use, and declare them. Compilation will fail if you try to use the vector for types you have not yet declared. Declaration is performed by modifying `gen_vector.h`. For example, if you wished to use the vector library for type `int` and type `float`, then you would add the following lines to `gen_vector.h`:

``` C
#define T int
#include "vector.h"
#undef T

#define T float
#include "vector.h"
#undef T
```

This will expose the functions of the vector library. The header file to use the vector container is `gen_vector.h`

```C
#include "gen_vector.h"

int main (int argv, char **argc) {
  int_vector vec;
  int_vec_init (&vec);
  
  
  float_vector vec2;
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

Available functions are as follows. replace `foo` below with any type you have declared as above

#### `void foo_vec_init (foo_vector* vector)`

Initialises the vector. Call this before any other functions.

#### `void foo_vec_free (foo_vector* vector)`

Deallocates memory requested for the vector. Call this when the vector is no longer required.

#### `size_t foo_vec_length (foo_vector* vector)`

Returns the (logical) length of the vector.

#### `size_t foo_vec_push (foo_vector* vector, foo elem)`

Push an element onto the end of the vector. On success, returns the new length of the vector. On failure, (insufficient memory) this function returns 0, and leaves the vector unmodified.

#### `foo foo_vec_pop (foo_vector* vector)`

Removes an element from the end of the vector. Returns the element.

#### `void foo_vec_set (foo_vector* vector, size_t index, foo elem)`

Set the element at `index` to `elem`.

#### `foo foo_vec_get (foo_vector* vector, size_t index)`

Returns the element at `index`.

#### `size_t foo_vec_insert ( foo_vector* v, size_t index, foo elem)`

Inserts a single element at a position given by 'index' and shifts the rest of the elements over by one. Returns the length of the vector on success, and on allocation failure, returns `0` and leaves the vectur unmodified.

#### `void foo_vec_delete (foo_vector* vector, size_t index)`

Deletes the element at `index`.

#### `size_t foo_vec_reserve ( foo_vector* v, size_t psize)`

Reserves enough memory for `psize` elements in the vector, but leaves the vector otherwise unmodified. Will return the new physical size of the vector. If there is an allocation failure, the old physical size is returned. If the reserved size is shorter than the length of the vector, the vector is shortened accordingly.
