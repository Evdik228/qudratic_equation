#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#include "solve_square.h"
#include "users_interaction.h"
#include "unit_tests.h"


#define RESET      "\033[0m"
#define RED        "\033[1;31m"
#define GREEN      "\033[1;32m"


bool is_error  = true;

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
                              {{  1, -1,  -6, 0, 0, 0}, TWO_ROOTS,    3,   -2}}; //это подгон(из за округления)


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

void Mistake_print(int a, Separate_test Tests []) {
    printf("%s\n-------------------------------------------------------------------\n\n%s", RED, RESET);
    printf("%sAnswer number %d is incorect!!!, please check more detailed!\n%s",RED , a + 1, RESET);
    printf("Yor answer: first root = %.2f, second root = %.2f , number of roots = %i\n", Tests[a].component.x1, Tests[a].component.x2, Tests[a].component.n_roots);
    printf("Right answer: first root = %.2f, second root = %.2f , number of roots = %i\n", Tests[a].x1_right, Tests[a].x2_right, Tests[a].n_roots_right);
}

int Run_tests() {
    for(int i = 0; i < 9; i++) {
        Tests[i].component.n_roots = Solves_equation(&(Tests[i].component));
        if (Is_right_answer(Tests[i] , i)) {
        } else {
            Mistake_print(i, Tests);
            is_error = false;
        }
    }
    if (is_error) {
        printf("%s\n-------------------------------------------------------------------\n\n%s", GREEN, RESET);
        printf("%sCheck completed, all correct!\n%s", GREEN, RESET);
        printf("%s\n-------------------------------------------------------------------\n\n%s", GREEN, RESET);
    } else {
        printf("%s\n-------------------------------------------------------------------\n\n%s", RED, RESET);
    }
    
    return 1;

}


