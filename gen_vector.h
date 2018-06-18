/* template macro */

#define TP(a, b) CAT(a, b)
#define CAT(a, b) a ## b

/* Define your types here. For example if you want to have a vector of
 * int, include the following lines:
 *
 * #define T int
 * #include "vector.h"
 * #undef T     
 *
 * The vector functions can then be invoked as "int_vec_init",
 * "int_vec_push", "int_vec_get" etc
 */

#define T int
#include "vector.h"
#undef T

#define T float
#include "vector.h"
#undef T
