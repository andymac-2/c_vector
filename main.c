#include <stdio.h>
#include <assert.h>

#include "gen_vector.h"

int main (void) {

  /* tests with int */
  
  int_vec vec;
  int_vec_init (&vec);

  assert (int_vec_length(&vec) == 0);

  for (int i = 100; i < 200; i++) {
    int_vec_push(&vec, i);
  }
  assert (int_vec_length(&vec) == 100);
  
  for (int i = 0; i < 100; i++) {
    assert (int_vec_get(&vec, i) == i + 100);
    int_vec_set(&vec, i, i);
  }
  assert (int_vec_length(&vec) == 100);

  for (int i = 0; i < 50; i++) {
    int_vec_delete(&vec, i);
  }
  assert (int_vec_length(&vec) == 50);

  for (int i = 0; i < 50; i++) {
    assert (int_vec_pop(&vec) == 99 - (i * 2));
  }
  assert (int_vec_length(&vec) == 0);

  assert(vec.psize == 16);

  int_vec_reserve (&vec, 100);
  assert(vec.psize == 100);

  for (int i = 0; i < 100; i++) {
    assert (vec.psize == 100);
    int_vec_push(&vec, i + 100);
    assert (int_vec_get(&vec, i) == i + 100);
  }
  
  int_vec_free (&vec);

  /* the same with floats */
  
  float_vec vec2;
  float_vec_init (&vec2);

  assert (float_vec_length(&vec2) == 0);

  for (float i = 100; i < 200; i++) {
    float_vec_push(&vec2, i);
  }
  assert (float_vec_length(&vec2) == 100);
  
  for (float i = 0; i < 100; i++) {
    assert (float_vec_get(&vec2, i) == i + 100);
    float_vec_set(&vec2, i, i);
  }
  assert (float_vec_length(&vec2) == 100);

  for (float i = 0; i < 50; i++) {
    float_vec_delete(&vec2, i);
  }
  assert (float_vec_length(&vec2) == 50);

  for (float i = 0; i < 50; i++) {
    assert (float_vec_pop(&vec2) == 99 - (i * 2));
  }
  assert (float_vec_length(&vec2) == 0);

  assert(vec2.psize == 16);

  float_vec_reserve (&vec2, 100);

  for (int i = 0; i < 100; i++) {
    assert (vec2.psize == 100);
    float_vec_push(&vec2, i + 100);
    assert (float_vec_get(&vec2, i) == i + 100);
  }

  for (int i = 0; i < 100; i++) {
    float_vec_insert(&vec2, 0, 99 - i);
  }

  for (int i = 0; i < 200; i++) {
    assert (float_vec_pop(&vec2) == 199 - i);
  }
  
  float_vec_free (&vec2);
}
