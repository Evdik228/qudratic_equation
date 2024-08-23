#ifndef  __S_SQUARE__
#define  __S_SQUARE__


struct quadratic_coefficients 
{
    double coef_one;
    double coef_two;
    double coef_three;
};

struct quadratic_roots
{
    double x1;
    double x2;
    int n_roots;
};


struct quadratic_components     
{
    quadratic_coefficients coefficients;
    quadratic_roots roots;
    
};

int Solves_equation(quadratic_components  *components);

#endif