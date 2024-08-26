#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <math.h>


#include "../include/work_vs_file.h"
#include "../include/solve_square.h"
#include "../include/users_interaction.h"
#include "../include/utilits.h"

#define RESET  "\033[0m"       
#define GREEN  "\033[1;32m" 

#define PRINT_GREEN(text) printf(GREEN text RESET)




void Solution_generation_linear_equation(int b, int c) {
    PRINT_GREEN("\nCheck the solution in the file solve.md\n\n");
}



void Solution_generation_quadratic_equation(double a, double b, double c) {
    PRINT_GREEN("\nCheck the solution in the file solve.md\n\n");

    FILE *add_file;

    add_file = fopen("solve.md", "w");

    double D = b*b - 4*a*c ;

    if (D > 0) {
        double x1 = (-b + sqrt(D))/(2*a);
        double x2 = (-b - sqrt(D))/(2*a);

        fprintf(add_file, "### Detailed visual solution of the equation\n");
        fprintf(add_file, " ## 1 Equation and answer\n");
        fprintf(add_file, ">$%.2f*x^2 - %.2fx + %.2f$  — The required equation.\n",a,b,c);
        fprintf(add_file, " - First root: $(\\textbf{x = %.2f)}$.\n",x1);
        fprintf(add_file, " - Second root: $(\\textbf{x = %.2f)}$.\n",x2);
        fprintf(add_file, "## 2 Solving\n");
        fprintf(add_file, " > First, let's analyze the coefficient a, it is not equal to zero, therefore we will solve the quadratic equation. Let's calculate the discriminant!\n");
        fprintf(add_file, "$$D = b^2 - 4ac$$\n");
        fprintf(add_file, "In our case: $a = %.2f$ ,  $b = %.2f$ , $c = %.2f$ , hence $\\Rightarrow$\n",a,b,c);
        fprintf(add_file, " $$D = (%.2f)^2 - 4*%.2f*%.2f = %.2f$$\n",b,a,c,D);
        fprintf(add_file, "$D > 0 \\Rightarrow$ Let's calculate the roots of the quadratic equation using the formula $x_{1,2} = \\frac{-b \\pm \\sqrt{D}}{2a}$\n");
        fprintf(add_file, "$$x_{1,2} = \\frac{-(%.2f) \\pm \\sqrt{%.2f}}{2 * %.2f}$$\n" , b, D, a);
        fprintf(add_file, ">Let's write down the roots of the desired equation\n");
        fprintf(add_file, "$$x_1 = %.2f $$ \n",x1);
        fprintf(add_file, "$$x_2 = %.2f $$\n",x2);
        fprintf(add_file, ">We hope that this solution was useful, thank you for using this program!\n");

    }else if (D == 0.0) {
        double x1 = -b /( 2 * a);

        fprintf(add_file, "### Detailed visual solution of the equation\n");
        fprintf(add_file, " ## 1 Equation and answer\n");
        fprintf(add_file, ">$%.2f*x^2 - %.2fx + %.2f$  — The required equation.\n",a,b,c);
        fprintf(add_file, " - One root: $(\\textbf{x = %.2f)}$.\n",x1);
        fprintf(add_file, "## 2 Solving\n");
        fprintf(add_file, " > First, let's analyze the coefficient a, it is not equal to zero, therefore we will solve the quadratic equation. Let's calculate the discriminant!\n");
        fprintf(add_file, "$$D = b^2 - 4ac$$\n");
        fprintf(add_file, "In our case: $a = %.2f$ ,  $b = %.2f$ , $c = %.2f$ , hence $\\Rightarrow$\n",a,b,c);
        fprintf(add_file, " $$D = (%.2f)^2 - 4*%.2f*%.2f = %.2f$$\n",b,a,c,D);
        fprintf(add_file, "$D = 0 \\Rightarrow$ Let's calculate the one root of the quadratic equation using the formula $x = \\frac{-b} {2a}$\n");
        fprintf(add_file, "$$x_{1,2} = \\frac{-(%.2f) }{2 * %.2f}$$\n" , b, a);
        fprintf(add_file, ">Let's write down the roots of the desired equation\n");
        fprintf(add_file, "$$x = %.2f $$ \n",x1);
        fprintf(add_file, ">We hope that this solution was useful, thank you for using this program!\n");

        
    } else {
        fprintf(add_file, "### Detailed visual solution of the equation\n");
        fprintf(add_file, " ## 1 Equation and answer\n");
        fprintf(add_file, ">$%.2f*x^2 - %.2fx + %.2f$  — The required equation.\n",a,b,c);
        fprintf(add_file, "### No roots!\n");
        fprintf(add_file, "## 2 Solving\n");
        fprintf(add_file, " > First, let's analyze the coefficient a, it is not equal to zero, therefore we will solve the quadratic equation. Let's calculate the discriminant!\n");
        fprintf(add_file, "$$D = b^2 - 4ac$$\n");
        fprintf(add_file, "In our case: $a = %.2f$ ,  $b = %.2f$ , $c = %.2f$ , hence $\\Rightarrow$\n",a,b,c);
        fprintf(add_file, " $$D = (%.2f)^2 - 4*%.2f*%.2f = %.2f$$\n",b,a,c,D);
        fprintf(add_file, "$D < 0 \\Rightarrow$ this equation has no solutions\n");
        fprintf(add_file, "### No roots! \n");
        fprintf(add_file, ">We hope that this solution was useful, thank you for using this program!\n");
    } 

}



void Solution_generation(){

    quadratic_coefficients coefficients = {};
    Data_entry(&coefficients);

    if (Comparison_zero(coefficients.coef_one)) {
            return Solution_generation_linear_equation(coefficients.coef_two, coefficients.coef_three);     
        } else {
            return Solution_generation_quadratic_equation(coefficients.coef_one, coefficients.coef_two, 
            coefficients.coef_three);              
        }

}
