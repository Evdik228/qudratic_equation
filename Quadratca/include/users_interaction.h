#ifndef  USERS_INTERACTION
#define  USERS_INTERACTION

#include "../include/solve_square.h"

inline const char* sqe     =  "--sqe";
inline const char* test    =  "--test";      
inline const char* file    =  "--file"; 
inline const char* add     =  "--add"; 
inline const char* help    =  "--help";
inline const char* solving = "--solving"; 


enum number_flag
{
    flag_HELP           = 1,
    flag_SOLVE_EQUATION = 2,
    flag_CHECK_ANSWERS  = 3,
    flag_FILE           = 4,
};

/**
 * @brief structure to determine which flag is called
 * 
 * @param flag_help  takes the value 1 if the flag -help is called 
 * @param  flag_solve_equation  takes the value 1 if the flag -sqe is called 
 * @param  flag_check_answers  takes the value 1 if the flag -test is called
 * @param  flag_file  takes the value 1 if the flag -file is called
 * @param  flag_add  takes the value 1 if the flag --add is called
 * @param scan_file_name contains the name of the file from which data is read
 * @param add_file_name contains the name of the file in which the response should be written
*/

struct is_number_flag 
{
    int  flag_help;
    int  flag_solve_equation;
    int  flag_check_answers;
    int  flag_file;
    int  flag_add;
    int  flag_solving_generation;
    char* scan_file_name;
    char* add_file_name;
};


void Data_output(quadratic_roots roots);

void Data_entry(quadratic_coefficients * coefficients);

int Check_flag(char* flag, is_number_flag * is_number);

void Print_help();

void Solve_equation();

void Terminal_interface(int argc, char *argv[]);

#endif // USERS_INTERACTION