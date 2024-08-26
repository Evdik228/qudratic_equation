/**
 * @file
 * @brief Utilits for program 
*/

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

#include "utilits.h"

const double EPSILON = 0.000001;

/**
 * @brief Compares a double number with zero to avoid error due to inaccuracy
*/

bool Comparison_zero(double a){
    if (fabs(a) <= EPSILON) {
        return true;
    }
    return false;
}

/**
 * @brief Compares two numbers of type double, to avoid errors due to inaccuracy
*/

bool Comparison_double(double a, double b){
    if (fabs(a - b) <= EPSILON){
        return true;
    }
    return false; 
}


/**
 * @brief clears the buffer in case of incorrect data entry
*/
bool Clean_boofer(){
    while (true){
        int ch = getchar();
        if (isspace(ch)) {
            break;
        } else if(ch == EOF){     
            return false;
        }
    }
    return true;
}



