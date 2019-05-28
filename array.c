#include <stdio.h>

int arr[1000], option, n, top, valueToInsert, indexToFind, i;

void push(void);
void pop(void);
void print(void);
void indexOf(void);
void printOptions(void);
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

    do
    {
        printOptions();
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
            indexOf();
            break;
        }
        case 5:
        {
            printf("\n<EXIT>\n\n");
            break;
        }
        default:
            printf("\n\t<Invalid option selected>");
            break;
        }
    } while (option!=5);
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
        scanf("%d",&valueToInsert);
        top++;
        arr[top]=valueToInsert;
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

// Method that implement indexOf functionallity for search the value of an element in the array by index.
void indexOf()
{
    if(top<=-1)
    {
        printf("\n<Array is empty>");
    }
    else
    {
        printf("\n\t  ::Enter a index to find> ");
        scanf("%d",&indexToFind);
        if(indexToFind>-1 && indexToFind < n)
        {        
            (indexToFind<=top) ? printf("\n\t<The value in the position %d is: %d>", indexToFind, arr[indexToFind]) : printf("\n\t<The value in the position %d is: empty>", indexToFind);
            indexToFind=0;        
        }
        else
        {
            printf("\n\t<Index %d is out of array range>", indexToFind);         
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

// Method that print the header of menu options.
void printOptions()
{
    printf("\n\n\t OPERATIONS USING ARRAY[%d/%d]", top+1, n);
    printf("\n\t--------------------------------");
    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.INDEXOF\n\t 5.EXIT \n\t");
}

