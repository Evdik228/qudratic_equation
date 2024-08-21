#include <stdio.h>
#include <math.h>

#include "header.h"
#include "solve_square.h"
#include "input_output.h"

// TODO: check for struct argument
int main()
{   
    /*initialization and entering variables*/

    quadratic_components  components = {0, 0, 0, 0, 0};  

    /*сalling function*/

    data_entry(&components);      

    int n_roots = Solves_equation(&components);

    data_output(n_roots, components.x1, components.x2);

    return 0;
}
