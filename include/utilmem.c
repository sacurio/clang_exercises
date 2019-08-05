#include <stdlib.h>

#include "util.h"
#include "utilarr.h"

void *mem_malloc(size_t size)
{
    darray *array = (darray *) malloc(size);
    if(array==NULL)
    {
        exit(0);
    }
    return array;
}