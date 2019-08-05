#include <stdio.h>
#include <stdlib.h>

#include "util.h"
#include "utilcons.h"
#include "utilarr.h"
#include "utilui.h"

darray *array_initialize()
{

    darray *dinamic_array = (darray*) malloc(sizeof(darray));

    dinamic_array->size = INITIAL_SIZE;
    dinamic_array->length = INITIAL_SIZE;
    dinamic_array->elements = (int*) malloc(INITIAL_SIZE*sizeof(int));

    for (int i = 0; i < dinamic_array->size; i++)
    {
        dinamic_array->elements[i] = get_random(i, 10000);
    }

    return dinamic_array;
}

void array_add(darray *darr, int element)
{
    darr->elements = realloc(darr->elements, sizeof(int));
    darr->elements[darr->size] = element;
    darr->size++;
    darr->length++;
}

void array_pop(darray * darr)
{
    for (int i = 0; i < darr->length-1; i++)
    {

    }

}

void array_free(darray *darr)
{
    free(darr->elements);
}

void *fill_array(int *array, int length)
{
    for (int i = 0; i < length; i++)
    {
        array[i] = 0;
    }
    return array;
}

void print(darray *array)
{
    intduo *maximum = get_maximum(array->elements, array->size);
    intduo *minimum = get_minimum(array->elements, array->size);
    int digits = count_digits(maximum->elementB) + PADDING_SPACE;

    int spaces = calculate_character_space(digits);
    int digits_element, digits_difference;
    char * horizontal_characters = string_repeat(spaces, HORIZONTAL_CHAR);

    //Printing array index

    print_warning();

    if (array->size==1){

        digits_element = count_digits(array->elements[0]);
        digits_difference = digits - 1;

        printf("\t%s%s%s\n", TOP_LEFT_CORNER_CHAR, horizontal_characters, TOP_RIGHT_CORNER_CHAR);
        printf("\t%s%s%d%s\n", VERTICAL_CHAR, string_repeat(digits_difference, SPACE_CHAR), array->size, VERTICAL_CHAR);
        printf("\t%s%s%s\n", BOTTOM_LEFT_CORNER_CHAR, horizontal_characters, BOTTOM_RIGHT_CORNER_CHAR);

        print_info();
        digits_element = count_digits(array->elements[0]);
        digits_difference = digits - digits_element;

        printf("\t%s%s%s\n", TOP_LEFT_CORNER_CHAR, horizontal_characters, TOP_RIGHT_CORNER_CHAR);
        printf("\t%s%s%d%s\n", VERTICAL_CHAR, string_repeat(digits_difference, SPACE_CHAR), array->elements[0], VERTICAL_CHAR);
        printf("\t%s%s%s\n", BOTTOM_LEFT_CORNER_CHAR, horizontal_characters, BOTTOM_RIGHT_CORNER_CHAR);

    }else {
        for (int i = 0; i < array->size; i++)
        {
            if (i==0){
                printf("\t%s%s%s", TOP_LEFT_CORNER_CHAR, horizontal_characters, HORIZONTAL_TOP_CENTER_CHAR);
            }else if(i==array->size-1){
                printf("%s%s\n", horizontal_characters, TOP_RIGHT_CORNER_CHAR);
            }else {
                printf("%s%s", horizontal_characters, HORIZONTAL_TOP_CENTER_CHAR);
            }
        }
        for (int i = 0; i < array->size; i++)
        {
            digits_element = count_digits(i);
            digits_difference = digits - digits_element;
            if(i==0){
                printf("\t");
            }
            printf("%s%s%d", VERTICAL_CHAR, string_repeat(digits_difference, SPACE_CHAR), i);
            if(i==array->size-1){
                printf("%s\n", VERTICAL_CHAR);
            }
        }

        for (int i = 0; i < array->size; i++)
        {
            if (i==0){
                printf("\t%s%s%s", BOTTOM_LEFT_CORNER_CHAR, horizontal_characters, HORIZONTAL_BOTTOM_CENTER_CHAR);
            }else if(i==array->size-1){
                printf("%s%s\n", horizontal_characters, BOTTOM_RIGHT_CORNER_CHAR);
            }else {
                printf("%s%s", horizontal_characters, HORIZONTAL_BOTTOM_CENTER_CHAR);
            }
        }

        //Printing array elements

        print_info();

        for (int i = 0; i < array->size; i++)
        {
            if (i==0){
                printf("\t%s%s%s", TOP_LEFT_CORNER_CHAR, horizontal_characters, HORIZONTAL_TOP_CENTER_CHAR);
            }else if(i==array->size-1){
                printf("%s%s\n", horizontal_characters, TOP_RIGHT_CORNER_CHAR);
            }else {
                printf("%s%s", horizontal_characters, HORIZONTAL_TOP_CENTER_CHAR);
            }
        }

        for (int i = 0; i < array->size; i++)
        {
            digits_element = count_digits(array->elements[i]);
            digits_difference = digits - digits_element;
            if(i==0){
                printf("\t");
            }
            printf("%s%s%d", VERTICAL_CHAR, string_repeat(digits_difference, SPACE_CHAR), array->elements[i]);
            if(i==array->size-1){
                printf("%s\n", VERTICAL_CHAR);
            }
        }

        for (int i = 0; i < array->size; i++)
        {
            if (i==0){
                printf("\t%s%s%s", BOTTOM_LEFT_CORNER_CHAR, horizontal_characters, HORIZONTAL_BOTTOM_CENTER_CHAR);
            }else if(i==array->size-1){
                printf("%s%s\n", horizontal_characters, BOTTOM_RIGHT_CORNER_CHAR);
            }else {
                printf("%s%s", horizontal_characters, HORIZONTAL_BOTTOM_CENTER_CHAR);
            }
        }

    }

    print_warning();
    printf("\tIndexes: %s%s", HORIZONTAL_CHAR, HORIZONTAL_CHAR);
    print_info();
    printf("\tValues: %s%s", HORIZONTAL_CHAR, HORIZONTAL_CHAR);

    printf("\n\n\t%sSize: %s%d\n", CL_DEFAULT, CL_HIGHLIGHT, array->size);
    printf("\t%sLenght: %s%d\n", CL_DEFAULT, CL_HIGHLIGHT, array->length);
    printf("\t%sMinimum: %s%d in [%d]\n", CL_DEFAULT, CL_HIGHLIGHT, minimum->elementB, minimum->elementA);
    printf("\t%sMaximum: %s%d in [%d]\n", CL_DEFAULT, CL_HIGHLIGHT, maximum->elementB, maximum->elementA);

    reset_color();

}

intduo *get_maximum(int * array, int length)
{
    intduo *intduo_var;
    int index;
    int maximum;
    for (int i = 0; i < length; i++)
    {
        if(i==0){
            maximum=array[i];
            index = i;
        }else{
            if(array[i]>maximum){
                maximum = array[i];
                index = i;
            }
        }
    }
    intduo_var = intduo_initialize(index, maximum);
    return intduo_var;
}

intduo *get_minimum(int * array, int length)
{
    intduo *intduo_var;
    int index;
    int minimum;
    for (int i = 0; i < length; i++)
    {
        if(i==0){
            minimum=array[i];
            index = i;
        }else{
            if(array[i]<minimum){
                minimum = array[i];
                index = i;
            }
        }
    }
    intduo_var = intduo_initialize(index, minimum);
    return intduo_var;
}