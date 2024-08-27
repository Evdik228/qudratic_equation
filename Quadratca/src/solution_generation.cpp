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


void Solution_generation_linear_equation(double b, double c) {

    FILE *add_file;

    add_file = fopen("solve.md", "w");

    PRINT_GREEN("\nCheck the solution in the file solve.md\n\n");

    if (b == 0 && c == 0){
        fprintf(add_file, "### Detailed visual solution of the equation\n");
        fprintf(add_file, " ## 1 Equation and answer\n");
        fprintf(add_file, "> $0*x = 0$  — The required equation.\n");
        fprintf(add_file, "### Infinity roots!\n");
        fprintf(add_file, "## 2 Solving\n");
        fprintf(add_file, " > First, let's analyze the coefficient a, it is equal to zero, therefore we will solve the linear equation.\n");
        fprintf(add_file, "In our case:  $b = 0$, and $c = 0$ hence $\\Rightarrow$\n");
        fprintf(add_file, "### Infinitely many roots!\n");
        fprintf(add_file, ">We hope that this solution was useful, thank you for using this program!\n");

        fclose(add_file);

    }else if(b == 0){

        fprintf(add_file, "### Detailed visual solution of the equation\n");
        fprintf(add_file, " ## 1 Equation and answer\n");
        fprintf(add_file, "> $%.2g = 0$  — The required equation.\n",c);
        fprintf(add_file, "### No roots!\n");
        fprintf(add_file, "## 2 Solving\n");
        fprintf(add_file, " > First, let's analyze the coefficient a, it is equal to zero, therefore we will solve the linear equation.\n");
        fprintf(add_file, "In our case:  $b = 0$ , hence $\\Rightarrow$\n");
        fprintf(add_file, "### No roots! \n");
        fprintf(add_file, ">We hope that this solution was useful, thank you for using this program!\n");

        fclose(add_file);

    }else {
        double x = -c/b;
        fprintf(add_file, "### Detailed visual solution of the equation\n");
        fprintf(add_file, " ## 1 Equation and answer\n");
        fprintf(add_file, "> $%.2g*x + %.2g = 0$  — The required equation.\n",b,c);
        fprintf(add_file, "- One root: %.2g\n", x);
        fprintf(add_file, "## 2 Solving\n");
        fprintf(add_file, " > First, let's analyze the coefficient a, it is equal to zero, therefore we will solve the linear equation.\n");
        fprintf(add_file, "In our case:  $b = 0$ , hence $\\Rightarrow$\n");
        fprintf(add_file, "Let's calculate the root of the linear equation using the formula $x = \\frac{-c}{b}$\n");
        fprintf(add_file, "$$x = \\frac{-(%.2g)}{%.2g}$$\n", c,b);
        fprintf(add_file, ">Let's write down the roots of the desired equation\n");
        fprintf(add_file, "$$x = %.2g $$ \n", x);
        fprintf(add_file, ">We hope that this solution was useful, thank you for using this program!\n");

        fclose(add_file);
    }

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
        fprintf(add_file, ">$%.2g*x^2 + %.2gx + %.2g = 0$  — The required equation.\n",a,b,c);
        fprintf(add_file, " - First root: $(\\textbf{x = %.2g)}$.\n",x1);
        fprintf(add_file, " - Second root: $(\\textbf{x = %.2g)}$.\n",x2);
        fprintf(add_file, "## 2 Solving\n");
        fprintf(add_file, " > First, let's analyze the coefficient a, it is not equal to zero, therefore we will solve the quadratic equation. Let's calculate the discriminant!\n");
        fprintf(add_file, "$$D = b^2 - 4ac$$\n");
        fprintf(add_file, "In our case: $a = %.2g$ ,  $b = %.2g$ , $c = %.2g$ , hence $\\Rightarrow$\n",a,b,c);
        fprintf(add_file, " $$D = (%.2g)^2 - 4*%.2g*%.2g = %.2g$$\n",b,a,c,D);
        fprintf(add_file, "$D > 0 \\Rightarrow$ Let's calculate the roots of the quadratic equation using the formula $x_{1,2} = \\frac{-b \\pm \\sqrt{D}}{2a}$\n");
        fprintf(add_file, "$$x_{1,2} = \\frac{-(%.2g) \\pm \\sqrt{%.2g}}{2 * %.2g}$$\n" , b, D, a);
        fprintf(add_file, ">Let's write down the roots of the desired equation\n");
        fprintf(add_file, "$$x_1 = %.2g $$ \n",x1);
        fprintf(add_file, "$$x_2 = %.2g $$\n",x2);
        fprintf(add_file, ">We hope that this solution was useful, thank you for using this program!\n");

        fclose(add_file);

    }else if (D == 0.0) {
        double x1 = -b /( 2 * a);

        fprintf(add_file, "### Detailed visual solution of the equation\n");
        fprintf(add_file, " ## 1 Equation and answer\n");
        fprintf(add_file, ">$%.2g*x^2 + %.2gx + %.2g = 0$  — The required equation.\n",a,b,c);
        fprintf(add_file, " - One root: $(\\textbf{x = %.2g)}$.\n",x1);
        fprintf(add_file, "## 2 Solving\n");
        fprintf(add_file, " > First, let's analyze the coefficient a, it is not equal to zero, therefore we will solve the quadratic equation. Let's calculate the discriminant!\n");
        fprintf(add_file, "$$D = b^2 - 4ac$$\n");
        fprintf(add_file, "In our case: $a = %.2g$ ,  $b = %.2g$ , $c = %.2g$ , hence $\\Rightarrow$\n",a,b,c);
        fprintf(add_file, " $$D = (%.2g)^2 - 4*%.2g*%.2g = %.2g$$\n",b,a,c,D);
        fprintf(add_file, "$D = 0 \\Rightarrow$ Let's calculate the one root of the quadratic equation using the formula $x = \\frac{-b} {2a}$\n");
        fprintf(add_file, "$$x_{1,2} = \\frac{-(%.2g) }{2 * %.2g}$$\n" , b, a);
        fprintf(add_file, ">Let's write down the roots of the desired equation\n");
        fprintf(add_file, "$$x = %.2g $$ \n",x1);
        fprintf(add_file, ">We hope that this solution was useful, thank you for using this program!\n");

        fclose(add_file);

    } else {
        fprintf(add_file, "### Detailed visual solution of the equation\n");
        fprintf(add_file, " ## 1 Equation and answer\n");
        fprintf(add_file, ">$%.2g*x^2 + %.2gx + %.2g = 0$  — The required equation.\n",a,b,c);
        fprintf(add_file, "### No roots!\n");
        fprintf(add_file, "## 2 Solving\n");
        fprintf(add_file, " > First, let's analyze the coefficient a, it is not equal to zero, therefore we will solve the quadratic equation. Let's calculate the discriminant!\n");
        fprintf(add_file, "$$D = b^2 - 4ac$$\n");
        fprintf(add_file, "In our case: $a = %.2g$ ,  $b = %.2g$ , $c = %.2g$ , hence $\\Rightarrow$\n",a,b,c);
        fprintf(add_file, " $$D = (%.2g)^2 - 4*%.2g*%.2g = %.2g$$\n",b,a,c,D);
        fprintf(add_file, "$D < 0 \\Rightarrow$ this equation has no solutions\n");
        fprintf(add_file, "### No roots! \n");
        fprintf(add_file, ">We hope that this solution was useful, thank you for using this program!\n");
        
        fclose(add_file);
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
