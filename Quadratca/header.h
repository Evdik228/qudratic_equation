#ifndef  __HEADER__
#define  __HEADER__

struct quadratic_components 
{
    double coef_one;
    double coef_two;
    double coef_three;
    double x1;
    double x2;
};

enum number_for_roots {    
    NO_ROOT   = 0,
    ONE_ROOT  = 1,
    TWO_ROOTS = 2,
    INF_ROOTS = 3,
}; 


#endif