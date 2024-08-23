#include <stdio.h>
#include <assert.h>
#include <ctype.h>


#include "work_vs_file.h"
#include "solve_square.h"
#include "users_interaction.h"


const char* name_file_right = "file.txt";


void Put_data_file(int n_roots, double x1, double x2, FILE *file){
    printf("result on file!\n");

    file = fopen(name_file_right, "w");

    switch (n_roots)
    {
    case NO_ROOT: fprintf(file, "No roots \n"); 
        break;
    case ONE_ROOT: fprintf(file, "One root: %.2f\n", x1);
        break;
    case TWO_ROOTS: fprintf(file, "First root:%.2f, Second root:%.2f\n", x1, x2);
        break;
    case INF_ROOTS: fprintf(file, "infinity roots\n");
        break;
    default: fprintf(file, "ERROR, another number of roots:%i\n", n_roots);
        break;
    }

}

void File_enterface(){

    FILE *file = NULL;

    quadratic_components file_components = {};

    if ((file = fopen(name_file_right, "r")) == NULL) {
        printf("Can't open file!");
    } 

    fscanf (file ,"%lg %lg %lg", &(file_components.coefficients.coef_one), 
            &(file_components.coefficients.coef_two), &(file_components.coefficients.coef_three)); 

    Solves_equation(&file_components);

    printf("put resalt on file? Y/N \n");

    if (getchar() == 'Y'){
        fclose (file); 
        file = NULL;
        Put_data_file(file_components.roots.n_roots, file_components.roots.x1, file_components.roots.x2, file);   
    } else {
        Data_output(file_components.roots);
    }


    fclose (file);

}