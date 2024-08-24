#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "solve_square.h"
#include "users_interaction.h"
#include "utilits.h"

/*function initialization*/

//TODO: isfinite and nan

int Solve_linear_equation (double * coef_two, double * coef_three, double * x1, int * n_roots) { 
    assert(coef_two != NULL);

    if (Comparison_zero(*coef_two)) {
        *n_roots = (Comparison_zero(*coef_three)) ? INF_ROOTS : NO_ROOT;
    } else {
        *x1 = -(*coef_three) / *coef_two; 
        *n_roots = ONE_ROOT;
    }
    return 0;
}

int Solve_quadratic_equation(quadratic_components * components) {
    double discriminant = (components->coefficients.coef_two) * (components->coefficients.coef_two)
                          - 4 * (components->coefficients.coef_one) * (components->coefficients.coef_three); 

    if (discriminant < 0) { 
        components->roots.n_roots = NO_ROOT; 
    } else if (Comparison_zero(discriminant)) { 
        components->roots.x1 = -(components->coefficients.coef_two) / (2 * (components->coefficients.coef_one));
        components->roots.n_roots = ONE_ROOT;
    } else {
        //  sqrt_D                                    
        components->roots.x1 = (-(components->coefficients.coef_two) - sqrt(discriminant)) 
        / (2 * (components->coefficients.coef_one));

        components->roots.x2 = (-(components->coefficients.coef_two) + sqrt(discriminant)) 
        / (2 * (components->coefficients.coef_one));

        components->roots.n_roots = TWO_ROOTS;
    }
    return 0;
}

// solve
int Solves_equation(quadratic_components * components) { 
    if (Comparison_zero(components->coefficients.coef_one)) {
        return Solve_linear_equation(&components->coefficients.coef_two, &components->coefficients.coef_three,
                                     &components->roots.x1, &components->roots.n_roots);     
    } else {
        return Solve_quadratic_equation(components);              
    }
}