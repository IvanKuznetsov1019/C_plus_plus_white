# Тренировочное задание по программированию: Справочник столиц

Реализуйте справочник столиц стран.

На вход программе поступают следующие запросы:

- **CHANGE_CAPITAL** **_country new_capital_** — изменение столицы страны **_country_** на **_new_capital_**, либо добавление такой страны с такой столицей, если раньше её не было.

- **RENAME** **_old_country_name new_country_name_** — переименование страны из **_old_country_name_** в **_new_country_name_**.

- **ABOUT** country — вывод столицы страны **_country_**.

- **DUMP** — вывод столиц всех стран.

#### Формат ввода

В первой строке содержится количество запросов Q, в следующих Q строках — описания запросов. Все названия стран и столиц состоят лишь из латинских букв, цифр и символов подчёркивания.

#### Формат вывода

Выведите результат обработки каждого запроса:

**В ответ на запрос CHANGE_CAPITAL** **_country new_capital_** **выведите**

- **Introduce new country** **_country_** **with capital** **_new_capital_**, если страны **_country_** раньше не существовало;

- **Country** **_country_** **hasn't changed its capital**, если страна **_country_** до текущего момента имела столицу **_new_capital_**;

- **Country** **_country_** **has changed its capital from** **_old_capital_** **to** **_new_capital_**, если страна **_country_** до текущего момента имела столицу **_old_capital_**, название которой не совпадает с названием **_new_capital_**.

**В ответ на запрос RENAME** **_old_country_name new_country_name_** **выведите**

- **Incorrect rename, skip**, если новое название страны совпадает со старым, страна **_old_country_name_** не существует или страна **_new_country_name_** уже существует;

- **Country** **_old_country_name_** **with capital** **_capital_** **has been renamed to** **_new_country_name_**, если запрос корректен и страна имеет столицу **_capital_**.

**В ответ на запрос ABOUT** **_country_** **выведите**

- **Country** **_country_** **doesn't exist**, если страны с названием **_country_** не существует;

- **Country** **_country_** **has capital** **_capital_**, если страна **_country_** существует и имеет столицу **_capital_**.

**В ответ на запрос DUMP выведите**

- **There are no countries in the world**, если пока не было добавлено ни одной страны;

- последовательность пар вида **_country/capital_**, описывающую столицы всех стран, если в мире уже есть хотя бы одна страна. При выводе последовательности пары указанного вида необходимо упорядочить по названию страны и разделять между собой пробелом.

#### Пример 1

**Ввод**

> 6
> CHANGE_CAPITAL RussianEmpire Petrograd
> RENAME RussianEmpire RussianRepublic
> ABOUT RussianRepublic
> RENAME RussianRepublic USSR
> CHANGE_CAPITAL USSR Moscow
> DUMP

**Вывод**

> Introduce new country RussianEmpire with capital Petrograd
> Country RussianEmpire with capital Petrograd has been renamed to RussianRepublic
> Country RussianRepublic has capital Petrograd
> Country RussianRepublic with capital Petrograd has been renamed to USSR
> Country USSR has changed its capital from Petrograd to Moscow
> USSR/Moscow

#### Пример 2

**Ввод**

> 24
> RENAME FakeCountry FarFarAway
> ABOUT FarFarAway
> DUMP
> CHANGE_CAPITAL TsardomOfRussia Moscow
> CHANGE_CAPITAL TsardomOfRussia Moscow
> CHANGE_CAPITAL ColonialBrazil Salvador
> CHANGE_CAPITAL TsardomOfRussia SaintPetersburg
> RENAME TsardomOfRussia RussianEmpire
> CHANGE_CAPITAL RussianEmpire Moscow
> CHANGE_CAPITAL RussianEmpire SaintPetersburg
> CHANGE_CAPITAL ColonialBrazil RioDeJaneiro
> DUMP
> RENAME ColonialBrazil EmpireOfBrazil
> ABOUT RussianEmpire
> RENAME EmpireOfBrazil UnitedStatesOfBrazil
> CHANGE_CAPITAL RussianEmpire Petrograd
> RENAME RussianEmpire RussianRepublic
> RENAME RussianRepublic USSR
> CHANGE_CAPITAL USSR Moscow
> CHANGE_CAPITAL UnitedStatesOfBrazil Brasilia
> RENAME UnitedStatesOfBrazil FederativeRepublicOfBrazil
> ABOUT RussianEmpire
> DUMP
> RENAME USSR USSR

**Вывод**

> Incorrect rename, skip
> Country FarFarAway doesn't exist
> There are no countries in the world
> Introduce new country TsardomOfRussia with capital Moscow
> Country TsardomOfRussia hasn't changed its capital
> Introduce new country ColonialBrazil with capital Salvador
> Country TsardomOfRussia has changed its capital from Moscow to SaintPetersburg
> Country TsardomOfRussia with capital SaintPetersburg has been renamed to RussianEmpire
> Country RussianEmpire has changed its capital from SaintPetersburg to Moscow
> Country RussianEmpire has changed its capital from Moscow to SaintPetersburg
> Country ColonialBrazil has changed its capital from Salvador to RioDeJaneiro
> ColonialBrazil/RioDeJaneiro RussianEmpire/SaintPetersburg
> Country ColonialBrazil with capital RioDeJaneiro has been renamed to EmpireOfBrazil
> Country RussianEmpire has capital SaintPetersburg
> Country EmpireOfBrazil with capital RioDeJaneiro has been renamed to UnitedStatesOfBrazil
> Country RussianEmpire has changed its capital from SaintPetersburg to Petrograd
> Country RussianEmpire with capital Petrograd has been renamed to RussianRepublic
> Country RussianRepublic with capital Petrograd has been renamed to USSR
> Country USSR has changed its capital from Petrograd to Moscow
> Country UnitedStatesOfBrazil has changed its capital from RioDeJaneiro to Brasilia
> Country UnitedStatesOfBrazil with capital Brasilia has been renamed to FederativeRepublicOfBrazil
> Country RussianEmpire doesn't exist
> FederativeRepublicOfBrazil/Brasilia USSR/Moscow
> Incorrect rename, skip

#### Пример 3

**Ввод**

> 10
> CHANGE_CAPITAL RussianEmpire Petrograd
> RENAME USSR RussianEmpire
> DUMP
> ABOUT USSR
> DUMP
> RENAME RussianEmpire RussianEmpire
> DUMP
> CHANGE_CAPITAL UnitedStatesOfBrazil Brasilia
> RENAME RussianEmpire UnitedStatesOfBrazil
> DUMP

**Вывод**

> Introduce new country RussianEmpire with capital Petrograd
> Incorrect rename, skip
> RussianEmpire/Petrograd
> Country USSR doesn't exist
> RussianEmpire/Petrograd
> Incorrect rename, skip
> RussianEmpire/Petrograd
> Introduce new country UnitedStatesOfBrazil with capital Brasilia
> Incorrect rename, skip
> RussianEmpire/Petrograd UnitedStatesOfBrazil/Brasilia
