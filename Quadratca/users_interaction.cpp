#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "solve_square.h"
#include "users_interaction.h"
#include "unit_tests.h"
#include "work_vs_file.h"


int Check_flag(char flag[]) { // TODO return enum 
    if (strcmp(sqe, flag) == 0){ 
        return flag_solve_equation; 
    } else if (strcmp(chans, flag) == 0) {
        return flag_check_answers;
    } else if (strcmp(file, flag) == 0) {
        return flag_file;
    } else {
        return flag_help;
    }
}

void Print_help() {
    printf("\n...   -sqe     ...  solve quadratic equation\n");
    printf("...   -chans   ...  check my unit tests\n");
    printf("...   -file    ...  scan coefficients from file\n\n");
}
    
void Solve_equation() {
    quadratic_components  components = {0, 0, 0, 0, 0, 0};  
    Data_entry(&components);      
    components.n_roots = Solves_equation(&components);
    Data_output(components.n_roots, components.x1, components.x2);
}

void Another_argument() {
    printf("Incorrect flag, if you don't know flag, add -help\n");
}

int Data_output(int n_roots, double x1, double x2){
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

int Data_entry(quadratic_components * components) {
    // TODO assert
    printf("Enter the coefficients of a quadratic equation of the form ax^2 + b^x +c: "); 
    while (scanf ("%lg %lg %lg", &(components->coef_one), &(components->coef_two), &(components->coef_three)) != 3) {
        printf("You have an input error, please enter the correct values!\n");
        printf("Enter the coefficients of a quadratic equation of the form ax^2 + b^x +c: ");
        int ch = 0;
        do {
            ch = getchar();
        } while(isspace(ch) && ch != EOF);
    }
    return 0;
}

void Terminal_interface(int argc, char *argv[]){ 
    if (argc == 1) { 
        printf("Add flag to the console, if you don't know flag, add -help\n");
        return;

    } else if (argc == 2) {

        switch (Check_flag(argv[1])) 
        {
        case flag_help: Print_help();
            break;
        case flag_solve_equation: Solve_equation(); 
            break;
        case flag_check_answers: Run_tests();
            break;
        case flag_file: File_enterface();
            break;
        default: Another_argument();
            break;
        }

    } else {
        printf ("Too much flags, add one\n");
    }
}