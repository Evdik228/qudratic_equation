# Quadratic equation
This project was created to solve a quadratic equation. The main idea is to solve equations completely with data input and output in a user-friendly way.

## 
- [Technologies](#technologies)
- [Strart working](#start-worcing)
- [Testing](#testing)
- [Flags](#flags)
- [Progect team](#progect-team)

## Technologies
- [C](https://www.w3schools.com/c/c_intro.php)
- [C++](https://www.w3schools.com/cpp/cpp_intro.asp)
- [GCC](https://gcc.gnu.org/)
- [Doxygen](https://www.doxygen.nl/)
- [Latex](https://www.latex-project.org/)

## Usage
In order to use my project, it needs to be uploaded to the development environment, preferably VS code. To compile the project, you need a Linux operating system or WSL (Windows Subsystem for Linux) installed. Enter into the console....
```sh
$ make
```

Separately about Unit tests. In order to enter your Unit tests, you need to use the structure in the file unit_tests.cpp
```cpp
struct separate_test
{   
    quadratic_components component;
    right_answers answers;
        
};

separate_test Tests [] =     {{{{  1,  2,  -3}, { 0, 0, NO_ROOT}},{ TWO_ROOTS,    1,   -3}},
                              {{{  0,  0,   0}, { 0, 0, NO_ROOT}},{ INF_ROOTS,    0,    0}},
                              {{{  0,  2,  -4}, { 0, 0, NO_ROOT}},{  ONE_ROOT,    2,    0}},
                              {{{  0,  0,   5}, { 0, 0, NO_ROOT}},{   NO_ROOT,    0,    0}}, 
                              {{{  1,  0,  -4}, { 0, 0, NO_ROOT}},{ TWO_ROOTS,    2,   -2}}, 
                              {{{  1,  2,   3}, { 0, 0, NO_ROOT}},{   NO_ROOT,    0,    0}}, 
                              {{{  1, -6,   9}, { 0, 0, NO_ROOT}},{  ONE_ROOT,    3,    0}}, 
                              {{{  4, -8,   0}, { 0, 0, NO_ROOT}},{ TWO_ROOTS,    0,    2}},
                              {{{  1, -1,  -6}, { 0, 0, NO_ROOT}},{ TWO_ROOTS,    3,   -2}}}; 
```

Add files to the Quadratica directory into which you want to write data or from which you want to read it. Enter the data into the file correctly, otherwise the program will not execute.

### Requirements
To install and run the project, you need [Linux](https://www.linux.org/) for make.

## Testing

Our project is covered with unit tests. To run them when activating the exe file, use the -test tag
```sh
./app -test
```
## Flags
   A brief description of the flags, you can read using the -help flag. The program supports reading several flags at the same time; if by mistake one flag was entered several times, it will be executed once. Falgs are executed in a fixed order.
- (-help): Information about flags for the user
```sh
./app -help
```
- (-sqe): Solves a quadratic equation using the entered coefficients and displays the answer to the console
```sh
./app -sqe
```
- (-test): Outputs the result of the testing unit, the data is taken from the structure described above
```sh
./app -test
```
- (-file): Reads data from a file if a file name is entered after the tag, reads data from there, if the file name is incorrect, reads from the base file
```sh
./app -file file.txt
```
- (--add): Writes data to a file, if a file name is entered after the falg, it will write to it, otherwise to the base
```sh
./app --add file.txt
```

## Project team


- [Evdokimov Dmitriy](https://t.me/Ev_dima) — chief developer
- [Dedinskiy Ilia](https://vk.com/ded32_ru) — team leader
- [Jitnikov Andrei](https://t.me/azhkov) — mentor, editor
- [Matvei Pavlov](https://vk.com/entryfrager) — mentor, editor


 