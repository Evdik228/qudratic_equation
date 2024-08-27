/**
 * @file
 * @brief Checks which flags have been entered into the system
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "../include/solve_square.h"
#include "../include/users_interaction.h"
#include "../include/unit_tests.h"
#include "../include/work_vs_file.h"
#include "../include/utilits.h"
#include "../include/solution_generation.h"

/**
 * @brief Checks which flags have been entered into the system
*/

void Execlusion_flags(is_number_flag * is_number) {
    if (is_number->flag_solve_equation == 1) {
        Solve_equation(); 
    } 
    if(is_number->flag_check_answers == 1) {        
        Run_tests();
    } 
    if(is_number->flag_file == 1) {
        File_enterface(is_number->flag_add, is_number->scan_file_name, is_number->add_file_name);
    } 
    if(is_number->flag_help) {
        Print_help();
    }
    if(is_number->flag_solving_generation) {
        Solution_generation();
    }
}

/**
 * @brief The function checks which flag the flag entered into the console belongs 
 * to if the flag is incorrect, it displays error information
*/

int Check_flag(char* flag, is_number_flag *is_number) {
    if (strcmp(sqe, flag) == 0) { 
        is_number->flag_solve_equation = 1;
        return 0;          
    } else if (strcmp(test, flag) == 0) {     
        is_number->flag_check_answers = 1;
        return 0;
    } else if (strcmp(help, flag) == 0) {
        is_number->flag_help = 1;
        return 0;
    } else if (strcmp(file, flag) == 0) {
        is_number->flag_file = 1;
        return 1;              
    } else if (strcmp(add, flag) == 0  && is_number->flag_file == 1) {
        is_number->flag_add = 1; 
        return 1;
    } else if (strcmp(solving, flag) == 0) {
        is_number->flag_solving_generation = 1; 
        return 1;
    } else {
        fprintf(stderr, "any flags not recognized!  add --help\n");
        return -1;          
    }
    return 0;
}

/**
 * @brief Displays data about flags 
*/

void Print_help() {
    printf("\n...   --sqe                      ...  solve quadratic equation\n");
    printf("...   --test                     ...  check my unit tests\n");
    printf("...   --file                     ...  scan coefficients from default file\n");
    printf("...   --file filename.txt        ...  scan coefficients from your file\n");
    printf("...   --file --add               ...  add answer in default file\n");
    printf("...   --file --add filename.txt  ...  add answer in your file\n");
    printf("...   --solving                  ...  Writes a detailed quadratic solution to a file\n\n");
}
    
/**
 * @brief Solve a quadratic equation if the -sqe flag is entered
*/

void Solve_equation() {  
    quadratic_components components = {};
    Data_entry(&components.coefficients);      
    Solves_equation(&components);
    Data_output(components.roots);
}

/**
 * @brief Function to output the response to the console
*/

void Data_output(quadratic_roots roots){
    switch (roots.n_roots)
    {
    case NO_ROOT: printf("No roots \n"); 
        break;
    case ONE_ROOT: printf("One root: %.2f\n", roots.x1);
        break;
    case TWO_ROOTS: printf("First root:%.2f, Second root:%.2f\n", roots.x1, roots.x2);
        break;
    case INF_ROOTS: printf("infinity roots\n");
        break;
    default: printf("ERROR, another number of roots:%i\n", roots.n_roots);
        break;
    }
}

/**
 * @brief Function to read data from the console
*/

void Data_entry(quadratic_coefficients * coefficients) {

    printf("\nEnter the coefficients of a quadratic equation of the form ax^2 + b^x +c: "); 
    while (scanf ("%lg %lg %lg", &(coefficients->coef_one), &(coefficients->coef_two), &(coefficients->coef_three)) != 3) {
        printf("You have an input error, please enter the correct values!\n");
        printf("Enter the coefficients of a quadratic equation of the form ax^2 + b^x +c: ");
        
        if (!Clean_boofer()){
            exit(0); 
        }

    }  
}

/**
 * @brief Reads and processes data about entered flags
*/

void Terminal_interface(int argc, char * argv[]){ 
    if (argc == 1) { 
        printf("Add flag to the console, if you don't know flag, add -help\n");
        return;

    } else {
        is_number_flag is_flag = {};     
        is_flag.add_file_name = (char *)add_file_name_default;
        is_flag.scan_file_name = (char *)scan_file_name_default;
        for (int number_flag = 1; number_flag < argc; number_flag++){
            int result = Check_flag(argv[number_flag], &is_flag);  
            if (result == 1 && number_flag + 1 != argc) {

                if (strcmp(argv[number_flag],  file) == 0 && argv[number_flag + 1][0] != '-') {
                    is_flag.scan_file_name = argv[number_flag + 1];
                    number_flag ++;

                } else if (strcmp(argv[number_flag], add) == 0  && argv[number_flag + 1][0] != '-') {
                    is_flag.add_file_name = argv[number_flag + 1];
                    number_flag ++;
                    
                }
            } else if (result == -1){
                break;
            }

        }
        Execlusion_flags(&is_flag);

    }   
}