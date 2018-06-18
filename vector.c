#ifndef INCLUDECFILE
#define INCLUDECFILE

#include "gen_vector.h"

#endif  /* INCLUDECFILE */


#ifdef T

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define STARTSIZE 8

/* constructor */
void TP(T, _vec_init) (TP(T, _vector) * v) {
  v->data = malloc (sizeof( T ) * STARTSIZE );
  v->psize = STARTSIZE;
  v->lsize = 0;
}

/* returns the logical size of the vector */
size_t TP(T, _vec_length) ( TP(T, _vector) * v) {
  return v->lsize;
}

/* Push an element to the end of the vector. Returns the size of the
 * array. Will return 0 if there is not sufficient memory. */
size_t TP (T, _vec_push) ( TP(T, _vector) * v, T elem) {
  if (v->lsize == v->psize) {
    v->psize *= 2;
    
    T * block;
    block = realloc(v->data, sizeof( T ) * v->psize);

    if (block == NULL) {
      v->psize /= 2;
      return 0;
    }

    v->data = block;
  }

  v->data[v->lsize] = elem;
  v->lsize ++;
  return v->lsize;
}

T TP (T, _vec_pop) ( TP(T, _vector) * v) {
  assert (v->lsize > 0);

  v->lsize --;

  T value = v->data[v->lsize];
  if (v->lsize <= ((v->psize / 4) - STARTSIZE)) {
    v->psize /= 2;
    v->data = realloc(v->data, sizeof( T ) * v->psize);
  }
  return value;
}

void TP (T, _vec_set) ( TP(T, _vector) * v, size_t index, T elem) {
  assert (index < v->lsize);
  assert (index >= 0);

  v->data[index] = elem;
}

T TP(T, _vec_get) ( TP(T, _vector) * v, size_t index) {
  assert (index < v->lsize);
  assert (index >= 0);

  return v->data[index];
}

void TP (T, _vec_delete) ( TP(T, _vector) * v, size_t index) {
  assert (index < v->lsize);
  assert (index >= 0);

  v->lsize --;
  memmove(&v->data[index], &v->data[index + 1], sizeof( T ) * (v->lsize - index));

  if (v->lsize <= ((v->psize / 4) - STARTSIZE)) {
    v->psize /= 2;
    v-> data = realloc(v->data, sizeof( T ) * v->psize);
  }
}

void TP (T, _vec_free) ( TP(T, _vector) * v) {
  free (v->data);
}

#endif  /* T */
