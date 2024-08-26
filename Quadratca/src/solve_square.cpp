/**
 * @file
 * @brief Solving a quadratic equation
*/

#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "../include/solve_square.h"
#include "../include/users_interaction.h"
#include "../include/utilits.h"

/*function initialization*/

//TODO: isfinite and nan


/**
 * @brief Function for solving a linear equation.
*/

int Solve_linear_equation (double * coef_two, double * coef_three, double * x1, int * n_roots) { 
    assert(coef_two != NULL);
    assert(coef_three != NULL);
    assert(x1 != NULL);
    assert(n_roots != NULL);

    if (Comparison_zero(*coef_two)) {
        *n_roots = (Comparison_zero(*coef_three)) ? INF_ROOTS : NO_ROOT;
    } else {
        *x1 = -(*coef_three) / *coef_two; 
        *n_roots = ONE_ROOT;
    }
    return 0;
}


/**
 * @brief Function for solving a quadratic equation
 * 
 * @details The function is triggered if the slope is greater than zero.
 *  Calculates the discriminant, compares it with zero and calculates the answer
*/


int Solve_quadratic_equation(quadratic_components * components) {
    assert(components->coefficients.coef_one != NULL);
    assert(components->coefficients.coef_two != NULL);
    assert(components->coefficients.coef_three != NULL);
    assert(components->roots.x1 != NULL);
    assert(components->roots.x2 != NULL);
    assert(components->roots.n_roots != NULL);

    double discriminant = (components->coefficients.coef_two) * (components->coefficients.coef_two)
                          - 4 * (components->coefficients.coef_one) * (components->coefficients.coef_three); 

    if (discriminant < 0) { 
        components->roots.n_roots = NO_ROOT; 
    } else if (Comparison_zero(discriminant)) { 
        components->roots.x1 = -(components->coefficients.coef_two) / (2 * (components->coefficients.coef_one));
        components->roots.n_roots = ONE_ROOT;
    } else {
                                            
        components->roots.x1 = (-(components->coefficients.coef_two) - sqrt(discriminant)) 
        / (2 * (components->coefficients.coef_one));

        components->roots.x2 = (-(components->coefficients.coef_two) + sqrt(discriminant)) 
        / (2 * (components->coefficients.coef_one));

        components->roots.n_roots = TWO_ROOTS;   
    }
    return 0;
}

/**
 * @brief function for solving a quadratic equation with given parameters
 * 
 * @details The implementation of this function contains a function for solving linear and quadratic equations
*/

int Solves_equation(quadratic_components * components) { 
    if (Comparison_zero(components->coefficients.coef_one)) {
        return Solve_linear_equation(&components->coefficients.coef_two, &components->coefficients.coef_three,
                                     &components->roots.x1, &components->roots.n_roots);     
    } else {
        return Solve_quadratic_equation(components);              
    }
}