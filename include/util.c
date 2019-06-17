#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>

#include "util.h"

uint8_t is_number(char *a)
{
    unsigned x;
    for ( x = 0; x < strlen ( a ); x++ )
        if ( !isdigit ( a[x] ) ) return 0;
    return 1;
}