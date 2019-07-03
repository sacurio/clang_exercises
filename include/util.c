#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>

#include "util.h"

uint8_t is_number(char *a)
{
    short i;
    for ( i = 0; i < strlen(a); i++ )
    {
        if (!isdigit (a[i])) return 0;
    }

    return 1;
}