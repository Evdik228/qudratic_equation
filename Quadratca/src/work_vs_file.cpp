/**
 * @file
 * @brief The file contains everything about working with the file
*/

#include <stdio.h>
#include <assert.h>
#include <ctype.h>


#include "../include/work_vs_file.h"
#include "../include/solve_square.h"
#include "../include/users_interaction.h"

/**
 * @brief Outputs data to a file
 * 
 * @details The function outputs data to a file, by file name; if there is no file with the same name, 
 * it creates a new file in the directory and outputs data to it
*/

void Put_data_file(int n_roots, double x1, double x2, char* add_file_name) {
    printf("result in file!\n");

    FILE *add_file = NULL;  

    if ((add_file = fopen(add_file_name, "w")) == NULL) {
        printf("There is no file with this name, data in file by default");
        add_file = fopen(ADD_FILE_NAME_DEFAULT, "w");
    } 

    switch (n_roots)
    {
    case NO_ROOT: fprintf(add_file, "No roots \n"); 
        break;
    case ONE_ROOT: fprintf(add_file, "One root: %.2f\n", x1);
        break;
    case TWO_ROOTS: fprintf(add_file, "First root:%.2f, Second root:%.2f\n", x1, x2);
        break;
    case INF_ROOTS: fprintf(add_file, "infinity roots\n");
        break;
    default: fprintf(add_file, "ERROR, another number of roots:%i\n", n_roots);
        break;
    }
    fclose(add_file);
}

void File_interface(int  flag_add, char* scan_file_name, char* add_file_name){

    FILE *scan_file;

    quadratic_components file_components = {};

    if ((scan_file = fopen(scan_file_name, "r")) == NULL) {
        printf("There is no file with this name, open file by default");
        scan_file = fopen(SCAN_FILE_NAME_DEFAULT, "r");
    } 

    fscanf (scan_file ,"%lg %lg %lg", &(file_components.coefficients.coef_one),   
            &(file_components.coefficients.coef_two), &(file_components.coefficients.coef_three)); 
    fclose (scan_file);

    Solves_equation(&file_components);

    if (flag_add == 1){
        Put_data_file(file_components.roots.n_roots, file_components.roots.x1, file_components.roots.x2, add_file_name); 
    } else {
        Data_output(file_components.roots);
    }
}