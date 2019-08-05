typedef struct darray{
    int size;
    int length;
    int *elements;
} darray;

darray *array_initialize();
// void array_redim();
void array_add(darray *darr, int element);
void array_free(darray *darr);
void array_pop(darray * darr);

void *fill_array(int *array, int length);
void print(darray *array);
intduo *get_maximum(int * array, int length);
intduo *get_minimum(int * array, int length);