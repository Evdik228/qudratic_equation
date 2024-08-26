#ifndef  __S_SQUARE__   
#define  __S_SQUARE__


/**
 * @brief enum for number of roots
 */
enum number_for_roots
{    
    NO_ROOT   = 0,
    ONE_ROOT  = 1,
    TWO_ROOTS = 2,
    INF_ROOTS = 3,
}; 

/**
 * @brief Structure for declaring the coefficients of a quadratic equation
 * @param coef_one coefficient a of equation 
 * @param coef_two coefficients b of equation
 * @param coef_three coefficients c of equation
*/

struct quadratic_coefficients 
{
    double coef_one; /// djfdhgf
    double coef_two;
    double coef_three;  
};

/**
 * @brief structure that contains information about the results of a decision
 * @param x1 first root, if there is one 
 * @param x2 second root, if there is one
 * @param n_roots number of roots
*/

struct quadratic_roots
{
    double x1;
    double x2;
    int n_roots;
};

/**
 * @brief structure that contains information about all quatratic aquation 
 * @param coefficients about coefficients 
 * @param roots about roots
*/

struct quadratic_components // ???   
{
    quadratic_coefficients coefficients;
    quadratic_roots roots;
    
};


int Solves_equation(quadratic_components  *components);

#endif