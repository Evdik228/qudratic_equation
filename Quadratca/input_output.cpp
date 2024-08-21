#include <stdio.h>

#include "solve_square.h"
#include "header.h"
#include "input_output.h"


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

int data_entry(quadratic_components  * components) {
    
    printf("Enter the coefficients of a quadratic equation of the form ax^2 + b^x +c :"); 
    while (scanf ("%lg %lg %lg", &(components->coef_one), &(components->coef_two), &(components->coef_three)) != 3) {
        printf("You have an input error, please enter the correct values!\n");
        printf("Enter the coefficients of a quadratic equation of the form ax^2 + b^x +c :");
    }
    return 0;
}