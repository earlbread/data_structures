/* vector.h */

#define VECTOR_INITIAL_CAPACITY 100

/* define a vector type */
struct vector {
  int size;
  int capacity;
  int *data;
};

void vector_init(struct vector *vector);
void vector_append(struct vector *vector, int value);
int vector_get(struct vector *vector, int index);
void vector_set(struct vector *vector, int index, int value);
void vector_double_capacity_if_full(struct vector *vector);
void vector_free(struct vector *vector);
