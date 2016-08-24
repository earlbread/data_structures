#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

void vector_init(struct vector *vector)
{
    vector->size = 0;
    vector->capacity = VECTOR_INITIAL_CAPACITY;
    vector->data = (int *)malloc(sizeof(int) * vector->capacity);
}

void vector_append(struct vector *vector, int value)
{
    vector_double_capacity_if_full(vector);

    vector->data[vector->size++] = value;
}

int vector_get(struct vector *vector, int index)
{
    if (index >= vector->size || index < 0) {
        printf("Index %d out of bounds for vector size %d\n",
                index, vector->size);
    }

    return vector->data[index];
}

void vector_set(struct vector *vector, int index, int value)
{
    while (vector->size <= index) {
        vector_append(vector, 0);
    }
    vector->data[index] = value;
}

void vector_double_capacity_if_full(struct vector *vector)
{
    if (vector->size >= vector->capacity) {
        vector->capacity *= 2;

        vector->data = 
            (int *)realloc(vector->data, sizeof(int) * vector->capacity);
    }
}

void vector_free(struct vector *vector)
{
    free(vector->data);
}

