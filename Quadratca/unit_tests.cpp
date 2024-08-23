#include <stdio.h>
#include <math.h>

#include "solve_square.h"
#include "users_interaction.h"
#include "unit_tests.h"
#include "utilits.h"
#include <assert.h>

#define RESET  "\033[0m"     
#define RED    "\033[1;31m"   //TODO **Make lib or struct for colors 
#define GREEN  "\033[1;32m" 



struct right_answers
{
    int                  n_roots_right;
    double               x1_right;
    double               x2_right;
};

struct separate_test
{   
    quadratic_components component;
    right_answers answers;
        
};

separate_test Tests [] =     {{{{  1,  2,  -3}, { 0, 0, NO_ROOT}},{ TWO_ROOTS,    1,   -3}},
                              {{{  0,  0,   0}, { 0, 0, NO_ROOT}},{ INF_ROOTS,    0,    0}},
                              {{{  0,  2,  -4}, { 0, 0, NO_ROOT}},{  ONE_ROOT,    2,    0}},
                              {{{  0,  0,   5}, { 0, 0, NO_ROOT}},{   NO_ROOT,    0,    0}}, 
                              {{{  1,  0,  -4}, { 0, 0, NO_ROOT}},{ TWO_ROOTS,    2,   -2}}, 
                              {{{  1,  2,   3}, { 0, 0, NO_ROOT}},{   NO_ROOT,    0,    0}}, 
                              {{{  1, -6,   9}, { 0, 0, NO_ROOT}},{  ONE_ROOT,    3,    0}}, 
                              {{{  4, -8,   0}, { 0, 0, NO_ROOT}},{ TWO_ROOTS,    0,    2}},
                              {{{  1, -1,  -6}, { 0, 0, NO_ROOT}},{ TWO_ROOTS,    3,   -2}}}; 
// const int number_of_tests = 9;
const int number_of_tests = sizeof(Tests) / sizeof(Tests[0]);
/*Check responses*/

bool Is_right_answer(separate_test test) { 
    if (test.component.roots.n_roots == test.answers.n_roots_right){
        if (Comparison_double(test.component.roots.x1 , test.answers.x1_right) 
            && Comparison_double(test.component.roots.x2 , test.answers.x2_right) 
            || Comparison_double(test.component.roots.x1 , test.answers.x2_right) 
            && Comparison_double(test.component.roots.x2 , test.answers.x1_right)){
            return true;
        }
    }
    return false;
}

void Mistake_print(int number, separate_test Tests []) { 
    printf("%s-------------------------------------------------------------------\n%s", RED, RESET);
    printf("%sTest number %d is INCORECT!!!, please check more detailed!\n%s",RED , number + 1, RESET);
    printf("Your answer: first root = %.2f, second root = %.2f , number of roots = %i\n",
           Tests[number].component.roots.x1, Tests[number].component.roots.x2, Tests[number].component.roots.n_roots);
    printf("Right answer: first root = %.2f, second root = %.2f , number of roots = %i\n",
           Tests[number].answers.x1_right, Tests[number].answers.x2_right, Tests[number].answers.n_roots_right);
}

int Run_tests() {
    int number_right_answer = 0;
    bool is_error  = true;

    for(int number = 0; number < number_of_tests; number++) { 
        Solves_equation(&(Tests[number].component));

        if (Is_right_answer(Tests[number])) {
            printf("%sTest number %i correct%s\n",GREEN, number + 1, RESET);
            number_right_answer++;
        } else {
            Mistake_print(number, Tests);
            is_error = false;
        }
    }

    if (is_error) {
        printf("%s-------------------------------------------------------------------\n%s", GREEN, RESET);
        printf("%sCheck completed, all correct!\n%s", GREEN, RESET);
        printf("%s-------------------------------------------------------------------\n%s", GREEN, RESET);
    } else {
        printf("%i/%i right!\n", number_right_answer, number_of_tests);
        printf("%s-------------------------------------------------------------------\n%s", RED, RESET);
    }
    
    return 1;

}


