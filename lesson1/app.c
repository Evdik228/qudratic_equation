#include <stdio.h>
#include <math.h>

enum roots {
    NO_ROOT   = 0,
    ONE_ROOT  = 1,
    TWO_ROOTS = 2,
    INF_ROOTS = 3,
};

/*function initialization*/
int SolvesSquare(double cuef_one, double cuef_two, double cuef_three, double *x1, double *x2) { 
    const double ZERO = 0.000001;
    double discriminant = 0; 

    if (fabs(cuef_one) <= ZERO) {
        if (fabs(cuef_two) <= ZERO) {
            
            return (fabs(cuef_three) <= ZERO) ? INF_ROOTS : 0;      
        } else {
            *x1 = -cuef_three /cuef_two; 
        }
    } else {
        discriminant = (cuef_two *cuef_two - 4 * cuef_one * cuef_three); 
    }

    if (discriminant <= ZERO) { 
        return NO_ROOT; 
    }
    else if (discriminant == 0) {
        *x1 = -cuef_two / (2 * cuef_one);
        return ONE_ROOT;
    } else {                                      
        *x1 = (-cuef_two - sqrt(discriminant)) / (2 * cuef_one);
        *x2 = (-cuef_two + sqrt(discriminant)) / (2 * cuef_one);
        return TWO_ROOTS;
    }
}

int data_output(int n_roots, double x1, double x2){
    switch (n_roots)
    {
    case NO_ROOT: printf("No roots \n"); 
        break;
    case ONE_ROOT: printf("One root: %.2f\n", x1);
        break;
    case TWO_ROOTS: printf("First root:%.2f, Second root:%.2f\n", x1, x2);
        break;
    case INF_ROOTS: printf("infinity roots\n");
        break;
    default: printf("ERROR, another number of roots:%i\n", n_roots);
        break;
    }
    return 0;
}

int data_entry(double * cuef_one, double * cuef_two, double * cuef_three) {
    
    printf("Enter the coefficients of a quadratic equation of the form ax^2 + b^x +c :"); 
    while (scanf ("%lg %lg %lg", cuef_one, cuef_two, cuef_three) != 3) {
        printf("You have an input error, please enter the correct values!\n");
        printf("Enter the coefficients of a quadratic equation of the form ax^2 + b^x +c :");
}
    return 0;
}

int main()
{   
    /*initialization and entering variables*/

    double cuef_one = 0,cuef_two = 0, cuef_three = 0;          
    double x1 = 0, x2 = 0;

    /*сalling function*/

    data_entry(&cuef_one, &cuef_two, &cuef_three);      

    int n_roots = SolvesSquare(cuef_one,cuef_two, cuef_three, &x1 , &x2);

    data_output(n_roots, x1, x2);

    return 0;
}
