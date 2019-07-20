#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#include "util.h"

//Number functions

uint8_t is_number(char *a)
{
    short i;
    for ( i = 0; i < strlen(a); i++ )
    {
        if (!isdigit (a[i])) return 0;
    }

    return 1;
}

//Ref: https://www.programiz.com/c-programming/examples/digits-count
int count_digits(int number)
{
    int aux_number = number;
    int count = 0;

    while(aux_number > 0)
    {
        aux_number /= 10;
        count++;
    }
    return count == 0 ? 1 : count;
}

int get_random(int min_num, int max_num)
{
    int result = 0, low_num = 0, hi_num = 0;

    if (min_num < max_num)
    {
        low_num = min_num;
        hi_num = max_num + 1; // include max_num in output
    } else {
        low_num = max_num + 1; // include max_num in output
        hi_num = min_num;
    }

    srand(time(NULL));
    result = (rand() % (hi_num - low_num)) + low_num;
    return result;
}

//Char functions

//Ref: https://rosettacode.org/wiki/Repeat_a_string#C
char * string_repeat(int times, const char * character)
{
    size_t slen = strlen(character);
    char * dest = malloc(times * slen+1);

    int i; char * p;
    for ( i=0, p = dest; i < times; ++i, p += slen ) {
        memcpy(p, character, slen);
    }
    *p = '\0';
    return dest;
}

//Array functions
int int_length(int * array)
{
    return sizeof(array) / sizeof(int);
}