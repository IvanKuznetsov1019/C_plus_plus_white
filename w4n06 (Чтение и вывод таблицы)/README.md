# Задание по программированию: Чтение и вывод таблицы

В первой строке файла input.txt записаны два числа N и M. Далее в файле находится таблица из N строк и M столбцов, представленная в формате CSV (comma-separated values). Такой формат часто используется для текстового представления таблиц с данными: в файле несколько строк, значения из разных ячеек внутри строки отделены друг от друга запятыми. Ваша задача — вывести данные на экран в виде таблицы. Формат таблицы:

1.  размер ячейки равен 10,

2.  соседние ячейки отделены друг от друга пробелом,

3.  последняя ячейка в строке НЕ оканчивается пробелом,

4.  последняя строка НЕ оканчивается символом перевода строки. Гарантируется, что в таблице будет ровно N строк и M столбцов, значение каждой из ячеек — целое число.

**Пример ввода**

> 2 3
> 1,2,3
> 4,5,6

**Пример вывода**

>         1          2          3
>         4          5          6
