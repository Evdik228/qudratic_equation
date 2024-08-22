#include <stdio.h>
#include <math.h>
#include <string.h>

#include "solve_square.h"
#include "users_interaction.h"
#include "unit_tests.h"

enum number_flag{
    flag_help = 1,
    flag_solve_equation = 2,
    flag_check_answers = 3,
};
    
int check_flag(char flag[]) {
    if (strcmp("-sqe", flag) == 0){
        return flag_solve_equation;
    } else if (strcmp("-chans", flag) == 0) {
        return flag_check_answers;
    } else {
        return flag_help;
    }
}

    void print_help() {
        printf("If you want solve quadratic equation, add flag -sqe\n");
        printf("If you want check answers, add flag -chans\n");
    }
    
    void solve_equation() {
        quadratic_components  components = {0, 0, 0, 0, 0, 0};  
        data_entry(&components);      
        components.n_roots = Solves_equation(&components);
        data_output(components.n_roots, components.x1, components.x2);
    }

    void another_argument() {
        printf("Incorrect flag, if you don't know flag, add -help\n");
    }

// TODO: -file "name.txt" fopen flose fscanf
int main(int argc, char *argv[])
{   

    if (argc == 1) { // TODO: func // to uesers interac
        printf("Add flag to the console, if you don't know flag, add -help\n");
        return 0;

    } else if (argc == 2) {
        int num_flag = check_flag(argv[1]); //

        switch (num_flag) 
        {
        case flag_help: print_help();
            break;
        case flag_solve_equation: solve_equation(); 
            break;
        case flag_check_answers: Run_tests();
            break;
        default: another_argument();
            break;
        }

    } else {
        printf ("Too much flags, add one\n");
    }

    return 0;
}
