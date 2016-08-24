#include <stdio.h>
#include "vector.h"

int main(void)
{
    struct vector vector;
    int i;
    
    vector_init(&vector);
    for (i = 200; i > -50; i--) {
        vector_append(&vector, i);
    }
    printf("Before vector size : %d, vector capacity %d\n",
            vector.size, vector.capacity);

    vector_set(&vector, 1234, 141551);
    printf("After vector size : %d, vector capacity %d\n",
            vector.size, vector.capacity);

    printf("Vector[%d] = %d\n", 27, vector_get(&vector, 27));

    return 0;
}
