# Задание по программированию: Сортировка без учёта регистра

#### Условие

В стандартном потоке дана одна строка, состоящая из числа N и следующих за ним N строк S. Между собой число и строки разделены пробелом.

Отсортируйте строки S в лексикографическом порядке по возрастанию, игнорируя регистр букв, и выведите их в стандартный поток вывода.

#### Ограничения

- 0 <= N <= 1000

- 1 <= |S| <= 15

- Каждая строка S[i] может состоять из следующих символов: [0-9,a-z,A-Z]

#### Примеры

| stdin      | stdout   |
| :--------- | :------- |
| 2 qq Aa    | Aa qq    |
| 3 aA Cc bb | aA bb Cc |

#### Подсказка

Обратите внимание на [функцию tolower](https://cplusplus.com/reference/cctype/tolower/).
