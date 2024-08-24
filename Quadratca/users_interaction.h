#ifndef  __USERS_INTERACTION__
#define  __USERS_INTERACTION__

    // TODO: codestyle for global var

#include "solve_square.h"

inline const char* sqe  =  "-sqe";
inline const char* test =  "-test";      
inline const char* file =  "-file"; 
inline const char* add  =  "--add"; 
inline const char* help =  "-help";


enum number_for_roots
{    
    NO_ROOT   = 0,
    ONE_ROOT  = 1,
    TWO_ROOTS = 2,
    INF_ROOTS = 3,
}; 

enum number_flag
{
    flag_HELP           = 1,
    flag_SOLVE_EQUATION = 2,
    flag_CHECK_ANSWERS  = 3,
    flag_FILE           = 4,
};

struct is_number_flag 
{
    int  flag_help;
    int  flag_solve_equation;
    int  flag_check_answers;
    int  flag_file;
    int  flag_add;
    char* scan_file_name;
    char* add_file_name;
};

void Data_output(quadratic_roots roots);
void Data_entry(quadratic_coefficients * coefficients);
int Check_flag(char* flag, is_number_flag * is_number);
void Print_help();
void Solve_equation();
void Terminal_interface(int argc, char *argv[]);

#endif // __USERS_INTERACTION__