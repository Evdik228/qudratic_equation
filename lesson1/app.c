#include <stdio.h>
#include <math.h>

enum roots {
    NO_ROOT   = 0,
    ONE_ROOT  = 1,
    TWO_ROOTS = 2,
    INF_ROOTS = 3,
}

/*function initialization*/
int SolvesSquare(double caf_one, double caf_two, double caf_three, double *x1, double *x2) { // rename
    const double ZERO = 0.000001;
    double diskr = 0; // rename
    if (fabs(caf_one) <= ZERO) {
        if (fabs(caf_two) <= ZERO) {
            return (fabs(caf_three) <= ZERO) ? INF_ROOTS : 0;      
        } else {
            *x1 = -caf_three /caf_two; 
        }
    } else {
        diskr = (caf_two *caf_two -4 * caf_one * caf_three); 
        return ONE_ROOT;
    }

    if (diskr <= ZERO) { 
        return NO_ROOT; 
    }
    else if (diskr == 0) {
        *x1 = -caf_two / (2 * caf_one);
        return ONE_ROOT;
    } else {                                      
        *x1 = (-caf_two - sqrt(diskr)) / (2 * caf_one);
        *x2 = (-caf_two + sqrt(diskr)) / (2 * caf_one);
        return TWO_ROOTS;
    }
}

int data_output(int n_roots, double x1, double x2){
    switch (n_roots)
    {
    case NO_ROOT: printf("No roots \n"); 
        break;
    case ONE_ROOT: printf("One root: %.2f", x1);
        break;
    case TWO_ROOTS: printf("First root:%.2f, Second root:%.2f", x1, x2);
        break;
    case INF_ROOTS: printf("infinity roots");
        break;
    default: printf("ERROR, another number of roots:%i", n_roots);
        break;
    }
    return 0;
}

int data_entry(double * caf_one, double * caf_two, double * caf_three) {
    
    printf("Enter rational numbers for first сoefficient,\nsecond coefficient, and third coefficient:"); 
    while (scanf ("%lg, %lg, %lg", c_one, c_two, c_three) != 3) {
        printf("You have an input error, please enter the correct values!");
    }
        
}

int main()
{   
    /*initialization and entering variables*/

    double caf_one = 0,caf_two = 0, caf_three = 0;          
    double x1 = 0, x2 = 0;

    /*сalling function*/

    data_entry(&caf_one, &caf_two, &caf_three);          

    int n_roots = SolvesSquare(caf_one,caf_two, caf_three, &x1 , &x2);

    data_output(n_roots, x1, x2);

    return 0;
}
