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
#include "include/utilarr.h"

#define SIZE 1000

/*********************************************************
*   Funcion prototypes
**********************************************************/
void print();
void print_options();

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

    darray *array;

    clear_screen();
    do
    {
        print_warning();
        print_options();
        printf("\n::Enter the option> ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
        {
            clear_screen();
            array = array_initialize();
            print(array);
            // push(&top, array_size);
            break;
        }
        case 2:
        {
            clear_screen();
            printf("\nSIZE: %d\n", array->size);
            array_add(array, input_number("Ingresar el valor:"));
            clear_screen();
            print(array);
            break;
        }
        case 3:
        {
            clear_screen();
            break;
        }
        case 4:
        {
            clear_screen();
            // find_by_index(top, array_size);
            break;
        }
        case 5:
        {
            clear_screen();
            // find_by_value(top, array_size);
            break;
        }
        case 6:
        {
            clear_screen();
            // sort(array_size);
            break;
        }
        case 7:
        {
            clear_screen();
            break;
        }
        case 8:
        {
            array_free(array);
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
    } while (option!=8);
}

void print_options()
{
    printf("\n\n\t OPERATIONS USING DYNAMIC ARRAYS");
    printf("\n\t--------------------------------");
    printf("\n\t 1.CREATE \n\t 2.PUSH\n\t 3.POP\n\t 4.PRINT\n\t 5.FIND BY INDEX\n\t 6.FIND BY VALUE\n\t 7.SORT\n\t 8.EXIT \n\t");
}