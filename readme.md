# Quadratic equation
Добавьте краткое описание проекта, опишите какую задачу он решает. 1-3 предложения будет достаточно. Добавьте бейджи для важных статусов проекта: статус разработки (в разработке, на поддержке и т.д.), статус билда, процент покрытия тестами и тд.

## Содержание
- [Technologies](#technologies)
- [Strart working](#start-worcing)
- [teating](#testing)
- [Contributing](#contributing)
- [To do](#to-do)
- [Progect team](#progect-team)

## Technologies
- [C] (https://www.w3schools.com/c/c_intro.php)
- [C++] (https://www.w3schools.com/cpp/cpp_intro.asp)
- [gcc](https://gcc.gnu.org/)
- [doxygen](https://www.doxygen.nl/)
- [Latex](https://www.latex-project.org/)

## Usage
In order to use my project, it needs to be uploaded to the development environment, preferably VS code. To compile the project, you need a Linux operating system or WSL (Windows Subsystem for Linux) installed. Enter into the console....
```sh
$ make clean   
$ make
```

Separately about Unit tests. In order to enter your Unit tests, you need to use the structure in the file unit_tests.cpp
```sh
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
To install and run the project, you need [Linux](https://www.linux.org/) or [WSL](https://learn.microsoft.com/ru-ru/windows/wsl/install).

## Testing

Our project is covered with unit tests. To run them when activating the exe file, use the -test tag
```sh
./app -test
```

## Contributing
Как помочь в разработке проекта? Как отправить предложение или баг-репорт. Как отправить доработку (оформить pull request, какие стайлгайды используются). Можно вынести в отдельный файл — [Contributing.md](./CONTRIBUTING.md).

### Why did we develop this project?
Чтобы был.

## To do
- [x] Добавить крутое README
- [ ] Всё переписать
- [ ] ...

## Project team


- [Богдан Звягинцев](tg://resolve?domain=bzvyagintsev) — Front-End Engineer

## Sources
 