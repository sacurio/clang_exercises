#include <stdio.h>
#include <stdlib.h>

#include "utilcons.h"
#include "utilarr.h"
#include "util.h"
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

    //fill_array(&dinamic_array->elements);

    return dinamic_array;
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
    // int digits = count_digits((int *)&array->size);
    int maximum = get_maximum(array->elements, array->size);
    int digits = count_digits(maximum) + PADDING_SPACE;
    int spaces = calculate_character_space(digits);
    int digits_element, digits_difference;
    char * horizontal_characters = string_repeat(spaces, HORIZONTAL_CHAR);

    //Printing array index

    print_warning();

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

    print_warning();
    printf("\tIndexes: %s%s", HORIZONTAL_CHAR, HORIZONTAL_CHAR);
    print_info();
    printf("\tValues: %s%s", HORIZONTAL_CHAR, HORIZONTAL_CHAR);

    reset_color();

}

int get_maximum(int * array, int length)
{
    int maximum = -1;
    for (int i = 0; i < length; i++)
    {
        maximum = array[i]>maximum? array[i]:maximum;
    }
    return maximum;
}