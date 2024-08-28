#ifndef  WORK_WITH_FILE
#define  WORK_WITH_FILE

inline const char* ADD_FILE_NAME_DEFAULT = "answers.txt"; // 
inline const char* SCAN_FILE_NAME_DEFAULT = "file.txt";



/**
 * @brief The function will work with the file.
 * 
 * @details The function writes data to a file or reads data from a file when using a special tag. 
 * The function implementation contains functions for reading data from a file and writing data to a file.
*/

void File_interface(int  flag_add, char* scan_file_name, char* add_file_name);

#endif  