# Quadratic equation
Добавьте краткое описание проекта, опишите какую задачу он решает. 1-3 предложения будет достаточно. Добавьте бейджи для важных статусов проекта: статус разработки (в разработке, на поддержке и т.д.), статус билда, процент покрытия тестами и тд.

## Содержание
- [Технологии](#технологии)
- [Начало работы](#начало-работы)
- [Тестирование](#тестирование)
- [Deploy и CI/CD](#deploy-и-ci/cd)
- [Contributing](#contributing)
- [To do](#to-do)
- [Команда проекта](#команда-проекта)

## Technologies
- [C/C++](https://www.w3schools.com/c/c_intro.php) (https://www.w3schools.com/cpp/cpp_intro.asp)
- [gcc](https://gcc.gnu.org/)
- [doxygen](https://www.doxygen.nl/)
- [Latex](https://www.latex-project.org/)

## Usage
In order to use my project, it needs to be uploaded to the development environment, preferably VS code. To compile the project, you need a Linux operating system or WSL (Windows Subsystem for Linux) installed.

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

И добавьте в свой проект:
```typescript
import { hi } from "your-awesome-plugin-name";

hi(); // Выведет в консоль "Привет!"
```

## Разработка

### Требования
Для установки и запуска проекта, необходим [NodeJS](https://nodejs.org/) v8+.

### Установка зависимостей
Для установки зависимостей, выполните команду:
```sh
$ npm i
```

### Запуск Development сервера
Чтобы запустить сервер для разработки, выполните команду:
```sh
npm start
```

### Создание билда
Чтобы выполнить production сборку, выполните команду: 
```sh
npm run build
```

## Тестирование
Какие инструменты тестирования использованы в проекте и как их запускать. Например:

Наш проект покрыт юнит-тестами Jest. Для их запуска выполните команду:
```sh
npm run test
```

## Deploy и CI/CD
Расскажите, как развернуть приложение. Как запустить пайплайны и т.д.

## Contributing
Как помочь в разработке проекта? Как отправить предложение или баг-репорт. Как отправить доработку (оформить pull request, какие стайлгайды используются). Можно вынести в отдельный файл — [Contributing.md](./CONTRIBUTING.md).

## FAQ 
Если потребители вашего кода часто задают одни и те же вопросы, добавьте ответы на них в этом разделе.

### Зачем вы разработали этот проект?
Чтобы был.

## To do
- [x] Добавить крутое README
- [ ] Всё переписать
- [ ] ...

## Команда проекта
Оставьте пользователям контакты и инструкции, как связаться с командой разработки.

- [Богдан Звягинцев](tg://resolve?domain=bzvyagintsev) — Front-End Engineer

## Источники
Если вы чем-то вдохновлялись, расскажите об этом: где брали идеи, какие туториалы смотрели, ссылки на исходники кода. 