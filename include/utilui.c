#include <stdio.h>
#include <stdlib.h>

#include "utilui.h"

void set_color(char color[])
{
    printf(color);
}
void reset_color(void)
{
    printf(CL_DEFAULT);
}
void print_default(void)
{
    set_color(CL_DEFAULT);
}
void print_info(void)
{
    set_color(CL_INFO);
}
void print_warning(void)
{
    set_color(CL_WARNING);
}
void print_danger(void)
{
    set_color(CL_DANGER);
}
void print_success(void)
{
    set_color(CL_SUCCESS);
}
void clear_screen(void)
{
    system("@cls||clear");
}
void pause(void)
{
  myflush(stdin);
  print_info();
  printf("\nPress [Enter] to continue . . .");
  print_default();
  fflush (stdout);
  getchar();
}
void myflush(FILE *in)
{
  int ch;
  do
    ch = fgetc (in);
  while ( ch != EOF && ch != '\n' );
  clearerr(in);
}