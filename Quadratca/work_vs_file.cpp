#include <stdio.h>


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

    FILE *file;

    quadratic_components file_components = {};

    //char name_file[1001];

    //printf("Add file name, not more than 1000 symbols: ");

    //fgets(name_file, 1001, stdin);
    
    //if (strcmp(name_file, ) == 0)

    if ((file = fopen(name_file_right, "r")) == NULL) {
        printf("Can't open file!");
    } 

    fscanf (file ,"%lg %lg %lg", &(file_components.coef_one), &(file_components.coef_two), &(file_components.coef_three)); 

    file_components.n_roots = Solves_equation(&file_components);

    printf("put resalt on file? Y/N \n");

    if (getchar() == 'Y'){
        fclose (file); 
        Put_data_file(file_components.n_roots, file_components.x1, file_components.x2, file);   
    } else {
        Data_output(file_components.n_roots, file_components.x1, file_components.x2);
    }


    fclose (file);





}