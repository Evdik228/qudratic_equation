#ifndef  __USERS_INTERACTION__
#define  __USERS_INTERACTION__

inline const char* sqe = "-sqe";
inline const char* chans = "-chans";      //спросить про *
inline const char* file = "-file"; 

struct quadratic_components 
{
    double coef_one;
    double coef_two;
    double coef_three;
    double x1;
    double x2;
    int n_roots;
};

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

int Data_output(int n_roots, double x1, double x2);
int Data_entry(quadratic_components * components);
int Check_flag(char flag[]);
void Print_help();
void Solve_equation();
void Another_argument();
void Terminal_interface(int argc, char *argv[]);

#endif