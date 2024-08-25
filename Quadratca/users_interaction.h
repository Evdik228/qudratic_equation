#ifndef  __USERS_INTERACTION__
#define  __USERS_INTERACTION__

// TODO: codestyle for global var

#include "solve_square.h"

inline const char* sqe  =  "-sqe";
inline const char* test =  "-test";      
inline const char* file =  "-file"; 
inline const char* add  =  "--add"; 
inline const char* help =  "-help";


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
    char* scan_file_name;
    char* add_file_name;
};

/**
 * @brief Function to output the response to the console
*/
void Data_output(quadratic_roots roots);

/**
 * @brief Function to read data from the console
*/
void Data_entry(quadratic_coefficients * coefficients);

/**
 * @brief The function checks which flag the flag entered into the console belongs 
 * to if the flag is incorrect, it displays error information
*/
int Check_flag(char* flag, is_number_flag * is_number);

/**
 * @brief Displays data about flags 
*/
void Print_help();

/**
 * @brief 
Solve a quadratic equation if the -sqe flag is entered
*/
void Solve_equation();

/**
 * @brief Reads and processes data about entered flags
*/
void Terminal_interface(int argc, char *argv[]);

#endif // __USERS_INTERACTION__