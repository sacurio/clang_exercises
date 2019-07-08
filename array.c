/*********************************************************
*   Autor: Sandy Acurio
*   Correo: sandy.acurio@gmail.com
**********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>

#include "include/utilui.h"
#include "include/util.h"

#define SIZE 1000

int arr[SIZE];

/*********************************************************
*   Funcion prototypes
**********************************************************/
void push(int *top, int array_size);
void pop(int *top);
void print(int top, int array_size);
void find_by_index(int top, int array_size);
void find_by_value(int top, int array_size);
void print_options(int top, int array_size);
void sort(int array_size);
void render_menu(void);

int main()
{
    render_menu();
    return 0;
}

/*********************************************************
*   Funcion: render_menu()
*
*   MAKE: Method for handle menu options by user selection.
*
**********************************************************/
void render_menu()
{
    int option;
    int number_valid = 0;
    int *top = -1;
    int *array_size = NULL;
    char number_str[10];
    char aux[3];
    clear_screen();
    do{
        print_info();
        printf("\n================================================");
        printf("\n::Enter size of array> ");
        scanf("%s", &aux);
        printf("================================================");
        reset_color();

        array_size = atoi(aux);
        number_valid = is_number(&aux);

        if(number_valid==1)
        {
            if (array_size>SIZE)
            {
                printf("<Error>");
            }
            do
            {
                print_options(top, array_size);
                printf("\n::Enter the option> ");
                scanf("%d", &option);
                switch (option)
                {
                case 1:
                {
                    clear_screen();
                    push(&top, array_size);
                    break;
                }
                case 2:
                {
                    clear_screen();
                    pop(&top);
                    break;
                }
                case 3:
                {
                    clear_screen();
                    print(top, array_size);
                    break;
                }
                case 4:
                {
                    clear_screen();
                    find_by_index(top, array_size);
                    break;
                }
                case 5:
                {
                    clear_screen();
                    find_by_value(top, array_size);
                    break;
                }
                case 6:
                {
                    clear_screen();
                    sort(array_size);
                    break;
                }
                case 7:
                {
                    clear_screen();
                    print_danger();
                    printf("\n<EXIT>\n\n");
                    print_default();
                    break;
                }
                default:
                    clear_screen();
                    print_danger();
                    printf("\n<Invalid option selected>");
                    print_default();
                    break;
                }
            } while (option!=7);
        }else{
            print_danger();
            printf("\n<The value entered is not a valid int number.>\n");
            print_default();
            number_valid = 0;
        }
    }while(number_valid==0);
}

/*********************************************************
*   Funcion: void push(int *top, int array_size)
*
*   IN: Take the last index of array an increment it.
        Read the size of the array.
*   MAKE: Method that implement push functionallity for
*           insert an element in array.
**********************************************************/
void push(int *top, int array_size)
{
    int value_to_insert;
    if(*top>=array_size-1)
    {
        print_danger();
        printf("\n<Array is over flow>");
        print_default();
    }
    else
    {
        print_info();
        printf("\n::Enter a value to be pushed for the position[%d]> ", *top+1);
        scanf("%d",&value_to_insert);
        print_default();
        *top = *top+1;
        arr[*top]=value_to_insert;
    }
}

/*********************************************************
*   Funcion: void pop(int *top)
*
*   IN: Take the last index of array and decrement it.
*   MAKE: Method that implement pop functionallity for remove
*           the last element in array.
*
**********************************************************/
void pop(int *top)
{
    if(*top<=-1)
    {
        print_warning();
        printf("\n<Array is empty>");
        print_default();
    }
    else
    {
        print_success();
        printf("\n<The popped elements is %d>",arr[*top]);
        print_default();
        *top = *top-1;
    }
}

/*********************************************************
*   Funcion: void find_by_index(int top, int array_size)
*
*   IN: Take the last index of the array and control if
        is not greater than size of array
*   MAKE: Method that find one element of array by index.
*
**********************************************************/
void find_by_index(int top, int array_size)
{
    int index_to_find;
    if(top<=-1)
    {
        print_danger();
        printf("\n<Array is empty>");
        print_default();
    }
    else
    {
        print_info();
        printf("\n::Enter a index to find> ");
        scanf("%d",&index_to_find);
        print_default();
        if(index_to_find>-1 && index_to_find < array_size)
        {
            print_success();
            (index_to_find<=top) ? printf("\n<The value in the position %d is: %d >\n", index_to_find, arr[index_to_find]) : printf("\n\t<The value in the position %d is: empty >", index_to_find);
            pause();
            clear_screen();
            print_default();
            index_to_find=0;
        }
        else
        {
            print_danger();
            printf("\n<Index %d is out of array range>", index_to_find);
            print_default();
        }
    }
}

/*********************************************************
*   Funcion: void find_by_value(int top, int array_size)
*
*   IN: Take the last index of the array and control if
        is not greater than size of array
*   MAKE: Method that find elements of array by value.
*
**********************************************************/
void find_by_value(int top, int array_size)
{
    int elements[10];
    int indexes[10];
    int k = 0;
    int value_to_find, j;

    if(top<=-1)
    {
        print_warning();
        printf("\n<Array is empty>");
        print_default();
    }
    else
    {
        print_info();
        printf("\n::Enter the value to find> ");
        scanf("%d",&value_to_find);
        print_default();
        for(j=0; j<array_size; j++)
        {
            if(arr[j]==value_to_find)
            {
                elements[k]=arr[j];
                indexes[k]=j;
                k++;
            }
        }

        if(k>0)
        {
            print_success();
            printf("\n::Element(s) founded:%d\n", k);
            printf("---------------------\n");
            for(j=0; j<k; j++)
            {
                printf("\n\tarray[%d]=%d\n", indexes[j], elements[j]);
            }
            pause();
            clear_screen();
            print_default();
        }
        else
        {
            print_warning();
            printf("\n<No elements founded by the value: %d>", value_to_find);
            print_default();
        }

    }
}

/*********************************************************
*   Funcion: void print(int top, int array_size)
*
*   IN: Take the last index of the array and control if
        is not greater than size of array
*   MAKE: Method for display the array elements in screen.
*
**********************************************************/
void print(int top, int array_size)
{
    if(top>=0)
    {
        print_success();
        printf("\nThe elements in array\n");
        printf("\n---------------------\n");
        for(int i=array_size-1; i>=0; i--)
            (top+1 > i) ? printf("\n\tarray[%d]=%d\n",i, arr[i]) : printf("\n\tarray[%d]=%s\n",i, "<empty>");
        print_default();
        pause();
        clear_screen();
    }
    else
    {
        print_warning();
        printf("\n<Array is empty>");
        print_default();
    }

}

/*********************************************************
*   Funcion: void sort(int top, int array_size)
*
*   IN: Take the last index of the array and control if
        is not greater than size of array
*   MAKE: Method that implements bubble sort algorithm.
*
**********************************************************/
void sort(int array_size)
{
    int i, j, hold;

    for(i = 1; i <= array_size; i++)
    {
        for(j=0; j<= array_size-2; j++)
        {
            if(arr[j] > arr[j+1])
            {
                hold = arr[j];
                arr[j] = arr[j+1];
                arr[j+1]=hold;
            }
        }
    }
    print_success();
    printf("<Array sorted>\n");
    print_default();
}

/*********************************************************
*   Funcion: void print_options(int top, int array_size)
*
*   IN: Take the last index of the array and control if
        is not greater than size of array
*   MAKE: Method that print the header of menu options.
*
**********************************************************/
void print_options(int top, int array_size)
{
    printf("\n\n\t OPERATIONS USING ARRAY[%d/%d]", top+1, array_size);
    printf("\n\t--------------------------------");
    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.FIND BY INDEX\n\t 5.FIND BY VALUE\n\t 6.SORT\n\t 7.EXIT \n\t");
}