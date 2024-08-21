#include <math.h>
#include <stdio.h>

#include "solve_square.h"
#include "header.h"
#include "input_output.h"

/*function initialization*/

bool Comparison_zero(double a){
    const double EPSILON = 0.00001;
    if (fabs(a) <= EPSILON) {
        return true;
    } else {
        return false;
    }
}

int Solve_linear_equation(quadratic_components * components) { 
    if (Comparison_zero((*components).coef_two)) {
        return (Comparison_zero((*components).coef_three)) ? INF_ROOTS : 0;      
    } else {
         components->x1 = -(*components).coef_three /(*components).coef_two; 
    }
    return 0;
}

int Solve_quadratic_equation(quadratic_components * components) {
    double discriminant = 0;

    discriminant = (pow((*components).coef_two, 2) - 4 * (*components).coef_one * (*components).coef_three); 

    if (Comparison_zero(discriminant)) { 
        return NO_ROOT; 
    } else if (discriminant == 0) { 
        components->x1 = -(*components).coef_two / (2 * (*components).coef_one);
        return ONE_ROOT;
    } else {                                      
        components->x1 = (-(*components).coef_two - sqrt(discriminant)) / (2 * (*components).coef_one);
        components->x2 = (-(*components).coef_two + sqrt(discriminant)) / (2 * (*components).coef_one);
        return TWO_ROOTS;
    }
    return 0;
}

int Solves_equation(quadratic_components  * components) { 
    if (Comparison_zero((*components).coef_one)) {
        return Solve_linear_equation(components);     
    } else {
        return Solve_quadratic_equation(components);              
    }
}