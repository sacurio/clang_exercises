typedef struct intduo{
    int elementA;
    int elementB;
} intduo;

intduo *intduo_initialize(int elementA, int elementB);

//Validation functions
u_int8_t is_number(char *a);
int get_random(int min_num, int max_num);

int count_digits(int number);

char * string_repeat(int times, const char * character);

int int_length(int * array);

int input_number(char * message);
char input_char(char * message);
