#include <stdio.h>
#include <stdlib.h>

#define INIT_CAP 200

typedef struct {
    int * p;
    size_t len;
    size_t cap;
} int_arr_t;

int_arr_t
int_arr_create()
{
    int_arr_t arr;
    arr.p = malloc(sizeof(*arr.p)*INIT_CAP);
    arr.len = 0;
    arr.cap = INIT_CAP;
    return arr;
}

void
append(int_arr_t * arr, int x)
{
    if (arr->len >= arr->cap) {
        arr->cap *= 2;
        arr->p = realloc(arr->p, sizeof(*arr->p)*arr->cap);
    }
    arr->p[arr->len] = x;
    arr->len++;
}

int
prod_sum(const int * numbers, size_t len, int sum)
{
    size_t i, j;
    for (i=0; i<len; i++) {
        int sought = sum - numbers[i];
        for (j = i+1; j < len; j++) {
            if (numbers[j] == sought)
                return numbers[i] * numbers[j];
        }
    }
    return -1;
}

int
main()
{
    char buffer[100];
    FILE * fp = fopen("../input.txt", "r");

    int_arr_t numbers = int_arr_create();

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        int x;
        sscanf(buffer, "%d", &x);
        append(&numbers, x);
    }

    fclose(fp);

    printf("%d\n", prod_sum(numbers.p, numbers.len, 2020));

    return 0;
}
