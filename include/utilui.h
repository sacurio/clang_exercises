#include <string.h>

#define CL_DEFAULT      "\x1b[0m"
#define CL_INFO         "\x1b[36m"
#define CL_WARNING      "\x1b[33m"
#define CL_DANGER       "\x1b[31m"
#define CL_SUCCESS      "\x1b[32m"
#define CL_HIGHLIGHT    "\x1b[97m"

//Color screen functions
void set_color(char color[]);
void reset_color(void);
void print_default(void);
void print_info(void);
void print_warning(void);
void print_danger(void);
void print_success(void);
void print_highlight(void);

//General screen functions
void clear_screen(void);
void pause(void);
void myflush(FILE *in);

//
int calculate_character_space(int character);