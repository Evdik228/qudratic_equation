#include <math.h>
#include <stdio.h>
#include <stdbool.h>

#include "solve_square.h"
#include "users_interaction.h"

// TODO: create utils.cpp

/*function initialization*/

bool Comparison_zero(double a){
    const double EPSILON = 0.00001;     // global
    if (fabs(a) <= EPSILON) {
        return true;
    }
    return false;
}

// x^2 + 2x = 0 -> x (x + 2)= 0 

// TODO not use struct

int Solve_linear_equation(quadratic_components * components) { 
    if (Comparison_zero(components->coef_two)) {
        components->n_roots = (Comparison_zero(components->coef_three)) ? INF_ROOTS : NO_ROOT;
        return (Comparison_zero(components->coef_three)) ? INF_ROOTS : NO_ROOT;      
    } else {
         components->x1 = -(components->coef_three) / components->coef_two; 
         components->n_roots = ONE_ROOT;
         return ONE_ROOT;
    }
    return 0;
}

int Solve_quadratic_equation(quadratic_components * components) {
    double discriminant = (components->coef_two) * (components->coef_two) - 4 * (components->coef_one) * (components->coef_three); 

    if (discriminant < 0) { 
        components->n_roots = NO_ROOT; 
        return NO_ROOT;
    } else if (Comparison_zero(discriminant)) { 
        components->x1 = -(components->coef_two) / (2 * (components->coef_one));
        components->n_roots = ONE_ROOT;
        return ONE_ROOT;
    } else {                                      
        components->x1 = (-(components->coef_two) - sqrt(discriminant)) / (2 * (components->coef_one));
        components->x2 = (-(components->coef_two) + sqrt(discriminant)) / (2 * (components->coef_one));
        components->n_roots = TWO_ROOTS;
        return TWO_ROOTS;
    }
    return 0;
}

int Solves_equation(quadratic_components  * components) { 
    if (Comparison_zero(components->coef_one)) {
        return Solve_linear_equation(components);     
    } else {
        return Solve_quadratic_equation(components);              
    }
}