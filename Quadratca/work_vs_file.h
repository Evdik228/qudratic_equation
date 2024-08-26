#ifndef  WORK_FILE
#define  WORK_FILE

inline const char* add_file_name_default = "answers.txt";
inline const char* scan_file_name_default = "file.txt";



/**
 * @brief The function will work with the file.
 * 
 * @details The function writes data to a file or reads data from a file when using a special tag. 
 * The function implementation contains functions for reading data from a file and writing data to a file.
*/

void File_enterface(int  flag_add, char* scan_file_name, char* add_file_name);

#endif  