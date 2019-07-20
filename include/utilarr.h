typedef struct darray{
    int size;
    int length;
    int *elements;
} darray;

darray *array_initialize();
// void array_redim();
// void array_free();
// void array_add(int element);
// void array_remove(int index);

void *fill_array(int *array, int length);
void print(darray *array);
int get_maximum(int * array, int length);