
#ifndef  __USERS_INTERACTION__
#define  __USERS_INTERACTION__

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



int data_output(int n_roots, double x1, double x2);
int data_entry(quadratic_components * components);

#endif