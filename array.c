#include <stdio.h>
#define SIZE 1000

int arr[SIZE], option, n, top, value_to_insert, index_to_find, i;

// Functions prototypes
void push(void);
void pop(void);
void print(void);
void find_by_index(void);
void find_by_value(void);
void print_options(void);
void sort(void);
void menu(void);

// Init function.
int main()
{
    top=-1;
    menu();
    return 0;    
}

// Method for handle menu options by user selection.
void menu()
{
    printf("\n================================================");
    printf("\n::Enter size of array> ");
    scanf("%d",  &n);

    if (n>1000)
    {
        printf("<Error>");        
    }
    

    do
    {
        print_options();
        printf("\n::Enter the option> ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
        {
            push();
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            print();
            break;
        }
        case 4:
        {
            find_by_index();
            break;
        }
        case 5:
        {
            find_by_value();
            break;
        }
        case 6:
        {
            sort();
            break;
        }
        case 7:
        {
            printf("\n<EXIT>\n\n");
            break;
        }
        default:
            printf("\n\t<Invalid option selected>");
            break;
        }
    } while (option!=7);
}

// Method that implement push functionallity for insert an element in array.
void push()
{
    if(top>=n-1)
    {
        printf("\n\t<Array is over flow>");         
    }
    else
    {
        printf("\n  ::Enter a value to be pushed for the position[%d]> ", top+1);
        scanf("%d",&value_to_insert);
        top++;
        arr[top]=value_to_insert;
    }
}

// Method that implement pop functionallity for remove the last element in array.
void pop()
{
    if(top<=-1)
    {
        printf("\n<Array is empty>");
    }
    else
    {
        printf("\n<The popped elements is %d>",arr[top]);
        top--;
    }
}

// Method that find one element of array by index.
void find_by_index()
{
    if(top<=-1)
    {
        printf("\n<Array is empty>");
    }
    else
    {
        printf("\n\t  ::Enter a index to find> ");
        scanf("%d",&index_to_find);
        if(index_to_find>-1 && index_to_find < n)
        {        
            (index_to_find<=top) ? printf("\n\t<The value in the position %d is: %d>", index_to_find, arr[index_to_find]) : printf("\n\t<The value in the position %d is: empty>", index_to_find);
            index_to_find=0;        
        }
        else
        {
            printf("\n\t<Index %d is out of array range>", index_to_find);         
        }
    }        
}

// Method that find elements of array by value.
void find_by_value()
{
    int elements[10];
    int indexes[10];
    int k = 0;
    int value_to_find, j;    
    
    if(top<=-1)
    {
        printf("\n<Array is empty>");
    }
    else
    {
        printf("\n\t  ::Enter the value to find> ", n);
        scanf("%d",&value_to_find);
        for(j=0; j<n; j++)
        {
            if(arr[j]==value_to_find)
            {
                elements[k]=arr[j];
                indexes[k]=j;
                printf("%d -- %d\n", j, arr[j]);
                k++;
            }
        }

        if(k>0)
        {
            printf("::Element(s) founded:%d\n", k);
            printf("::-------------------\n");
            for(j=0; j<k; j++)
            {
                printf("\n\tarray[%d]=%d", indexes[j], elements[j]);
            }
        }
        else
        {
            printf("\n<No elements founded by the value: %d>", value_to_find);   
        }      

    }        
}

// Method for display the array elements in screen.
void print()
{
    if(top>=0)
    {
        printf("\nThe elements in array\n");
        printf("\n---------------------\n");
        for(i=n-1; i>=0; i--)
            (top+1 > i) ? printf("\n\tarray[%d]=%d\n",i, arr[i]) : printf("\n\tarray[%d]=%s\n",i, "<empty>");           
        printf("\n\n::Enter the option> ");
    }
    else
    {
        printf("\n <Array is empty>");
    }
    
}

// Method that implements bubble sort algorithm.
void sort()
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
    printf("<Array sorted>");    
}

// Method that print the header of menu options.
void print_options()
{
    printf("\n\n\t OPERATIONS USING ARRAY[%d/%d]", top+1, n);
    printf("\n\t--------------------------------");
    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.FIND BY INDEX\n\t 5.FIND BY VALUE\n\t 6.SORT\n\t 7.EXIT \n\t");
}