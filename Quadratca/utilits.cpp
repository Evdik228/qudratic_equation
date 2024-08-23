#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

#include "utilits.h"

const double EPSILON = 0.000001;

bool Comparison_zero(double a){
    if (fabs(a) <= EPSILON) {
        return true;
    }
    return false;
}

bool Comparison_double(double a, double b){
    if (fabs(a - b) <= EPSILON){
        return true;
    }
    return false; 
}

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



