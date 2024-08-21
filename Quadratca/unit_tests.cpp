#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#include "solve_square.h"
#include "users_interaction.h"
#include "unit_tests.h"



struct Separate_test
{   
    quadratic_components component;
    int n_roots_right;
    double x1_right;
    double x2_right;
    
};

Separate_test Tests [] =     {{{  1,  2,  -3, 0, 0, 0}, TWO_ROOTS,    1,   -3},
                              {{  0,  0,   0, 0, 0, 0}, INF_ROOTS,    0,    0},
                              {{  0,  2,  -4, 0, 0, 0},  ONE_ROOT,    2,    0},
                              {{  0,  0,   5, 0, 0, 0},   NO_ROOT,    0,    0}, 
                              {{  1,  0,  -4, 0, 0, 0}, TWO_ROOTS,    2,   -2}, 
                              {{  1,  2,   3, 0, 0, 0},   NO_ROOT,    0,    0}, 
                              {{  1, -6,   9, 0, 0, 0},  ONE_ROOT,    3,    0}, 
                              {{  4, -8,   0, 0, 0, 0}, TWO_ROOTS,    0,    2},
                              {{  1, -1,  -6, 0, 0, 0}, TWO_ROOTS,    3,  -2}}; //это подгон(из за округления)

int is_right [] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

/*Check responses*/

bool Is_right_answer(Separate_test test, int i) {
    if (test.component.n_roots == test.n_roots_right){
        if (test.component.x1 == test.x1_right && test.component.x2 == test.x2_right  ||  test.component.x1 == test.x2_right && test.component.x2 == test.x1_right){
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
    return true;
}

void Mistake_print() {
 //pass
}

int Run_tests() {
    for(int i = 0; i < 9; i++) {
        Tests[i].component.n_roots = Solves_equation(&(Tests[i].component));
        if (Is_right_answer(Tests[i] , i)) {
            continue;
        } else {
            printf("Answer number %d is incorect!!!, please check more detailed!\n", i+1);
            printf("Yor answer: first root = %.2f, second root = %.2f , number of roots = %i\n", Tests[i].component.x1, Tests[i].component.x2, Tests[i].component.n_roots);
            printf("Right answer: first root = %.2f, second root = %.2f , number of roots = %i\n", Tests[i].x1_right, Tests[i].x2_right, Tests[i].n_roots_right);
            return 0;
        }
    }
    printf("Check completed, all correct!\n");
    return 1;

}


