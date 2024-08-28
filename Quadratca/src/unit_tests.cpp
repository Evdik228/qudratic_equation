/**
 * @file
 * @brief Unit test file
*/

#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "../include/solve_square.h"
#include "../include/users_interaction.h"
#include "../include/unit_tests.h"
#include "../include/utilits.h"


#define RESET  "\033[0m"     
#define RED    "\033[1;31m"   
#define GREEN  "\033[1;32m" 

#define PRINT_RED(text)  printf(RED text RESET);
#define PRINT_GREEN(text) printf(GREEN text RESET)                          
 
/**
 * @brief Contains the correct roots and the correct number of roots (hammered into the system)
 * @param x1_right right first root
 * @param x2_right right second root
 * @param n_roots_right right number of roots
*/

struct right_answers
{
    int    n_roots_right;
    double x1_right;
    double x2_right;
};

struct separate_test
{   
    quadratic_components component;
    right_answers answers;     
};

separate_test Tests [] =   {{{{ 1,  2, -3}, { 0, 0, NO_ROOT}}, { TWO_ROOTS, 1, -3}},
                            {{{ 0,  0,  0}, { 0, 0, NO_ROOT}}, { INF_ROOTS, 0,  1}},
                            {{{ 0,  2, -4}, { 0, 0, NO_ROOT}}, {  ONE_ROOT, 2,  0}},
                            {{{ 0,  0,  5}, { 0, 0, NO_ROOT}}, {   NO_ROOT, 0,  0}}, 
                            {{{ 1,  0, -4}, { 0, 0, NO_ROOT}}, { TWO_ROOTS, 2, -2}}, 
                            {{{ 1,  2,  3}, { 0, 0, NO_ROOT}}, {   NO_ROOT, 0,  0}}, 
                            {{{ 1, -6,  9}, { 0, 0, NO_ROOT}}, {  ONE_ROOT, 3,  0}}, 
                            {{{ 4, -8,  0}, { 0, 0, NO_ROOT}}, { TWO_ROOTS, 0,  2}},
                            {{{ 1, -1, -6}, { 0, 0, NO_ROOT}}, { TWO_ROOTS, 3, -2}}}; 


const int number_of_tests = sizeof(Tests) / sizeof(Tests[0]);

/**
 * @brief The function compares the answer entered into the system with the one issued by the program,
 *  and if there is a discrepancy, it reports an error
*/

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

/**
 * @brief The function prints an error message to the console
*/

void Mistake_print(int number, separate_test Tests []) { 
    PRINT_RED("-------------------------------------------------------------------\n");
    printf("%sTest number %d is INCORECT!!!, please check more detailed!\n%s",RED , number + 1, RESET);
    printf("Your answer: first root = %.2f, second root = %.2f , number of roots = %i\n",
           Tests[number].component.roots.x1, Tests[number].component.roots.x2, Tests[number].component.roots.n_roots);
    printf("Right answer: first root = %.2f, second root = %.2f , number of roots = %i\n",
           Tests[number].answers.x1_right, Tests[number].answers.x2_right, Tests[number].answers.n_roots_right);
}


/**
 * @brief function that runs the verification of pre-prepared tests and provides information about the verification.
 * 
 * @details The implementation of this function contains a function for comparing prepared answers,
 *  and the answers issued by the Solve_equation function, as well as a function for outputting test results to the console
*/


int Run_tests() {
    int number_right_answer = 0;
    bool is_error = true;

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
        PRINT_GREEN("-------------------------------------------------------------------\n");
        PRINT_GREEN("Check completed, all correct!\n");
        PRINT_GREEN("-------------------------------------------------------------------\n");
    } else {
        printf("%i/%i right!\n", number_right_answer, number_of_tests);
        PRINT_RED("-------------------------------------------------------------------\n");
    }
    
    return 1;

}


