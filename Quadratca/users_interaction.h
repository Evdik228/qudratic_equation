#ifndef  __USERS_INTERACTION__
#define  __USERS_INTERACTION__

// TODO: codestyle for global var

#include "solve_square.h"

inline const char* sqe = "-sqe";
inline const char* chans = "-chans";      
inline const char* file = "-file"; 

enum number_for_roots {    
    NO_ROOT   = 0,
    ONE_ROOT  = 1,
    TWO_ROOTS = 2,
    INF_ROOTS = 3,
}; 

enum number_flag{
    flag_help = 1,
    flag_solve_equation = 2,
    flag_check_answers = 3,
    flag_file = 4,
};

void Data_output(quadratic_roots roots);
void Data_entry(quadratic_coefficients * coefficients);
int Check_flag(char flag[]);
void Print_help();
void Solve_equation();
void Another_argument();
void Terminal_interface(int argc, char *argv[]);

#endif // __USERS_INTERACTION__