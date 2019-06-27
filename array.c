#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>

#include "include/utilui.h"

#define SIZE 1000

int arr[SIZE], top, i;

// Functions prototypes
void push(int *top, int *n);
void pop(void);
void print(int *n);
void find_by_index(int *n);
void find_by_value(int *n);
void print_options(int *n);
void sort(int *n);
void render_menu(void);

// Init function.
int main()
{
    render_menu();
    return 0;
}

// Method for handle menu options by user selection.
void render_menu()
{
    int option; 
    int *top, *n;
    top=-1;
    int number_valid = 0;
    char number_str[10];
    clear_screen();
    do{
        print_info();
        printf("\n================================================");
        printf("\n::Enter size of array> ");
        scanf("%d", &n);
        printf("================================================");
        reset_color();
        sscanf(number_str, "%s", &n);
        number_valid = is_number(number_str);
        printf("%d %d", number_valid, *n);
        if(number_valid==1)
        {
            if (n>SIZE)
            {
                printf("<Error>");
            }
            do
            {
                print_options(n);
                printf("\n::Enter the option> ");
                scanf("%d", &option);
                switch (option)
                {
                case 1:
                {
                    clear_screen();
                    push(&top, &n);
                    break;
                }
                case 2:
                {
                    clear_screen();
                    pop();
                    break;
                }
                case 3:
                {
                    clear_screen();
                    print(&n);
                    break;
                }
                case 4:
                {
                    clear_screen();
                    find_by_index(&n);
                    break;
                }
                case 5:
                {
                    clear_screen();
                    find_by_value(&n);
                    break;
                }
                case 6:
                {
                    clear_screen();
                    sort(&n);
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

// Method that implement push functionallity for insert an element in array.
void push(int *top, int *n)
{
    int value_to_insert;
    if(top>=n-1)
    {
        print_danger();
        printf("\n<Array is over flow>");
        print_default();
    }
    else
    {
        print_info();
        printf("\n::Enter a value to be pushed for the position[%d]> ", top+1);
        scanf("%d",&value_to_insert);
        print_default();
        top++;
        arr[*top]=value_to_insert;
    }
}

// Method that implement pop functionallity for remove the last element in array.
void pop()
{
    if(top<=-1)
    {
        print_warning();
        printf("\n<Array is empty>");
        print_default();
    }
    else
    {
        print_success();
        printf("\n<The popped elements is %d>",arr[top]);
        print_default();
        top--;
    }
}

// Method that find one element of array by index.
void find_by_index(int *n)
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
        if(index_to_find>-1 && index_to_find < n)
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

// Method that find elements of array by value.
void find_by_value(int *n)
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
        for(j=0; j<n; j++)
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

// Method for display the array elements in screen.
void print(int *n)
{
    if(top>=0)
    {
        print_success();
        printf("\nThe elements in array\n");
        printf("\n---------------------\n");
        for(i=n-1; i>=0; i--)
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

// Method that implements bubble sort algorithm.
void sort(int *n)
{
    int i, j, hold;

    for(i = 1; i <= n; i++)
    {
        for(j=0; j<= n-2; j++)
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
    print(n);
    print_default();
}

// Method that print the header of menu options.
void print_options(int *n)
{
    printf("\n\n\t OPERATIONS USING ARRAY[%d/%d]", top+1, n);
    printf("\n\t--------------------------------");
    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.FIND BY INDEX\n\t 5.FIND BY VALUE\n\t 6.SORT\n\t 7.EXIT \n\t");
}