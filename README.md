# **Лабораторная работа №1 "Алгебра полиномов"**

**«Нижегородский государственный университет им. Н.И. Лобачевского»**

**Институт информационных технологий, математики и механики**

Исполнители,

:smile: студент гр. 3822Б1ПР2 Сорокин А.А.

:smirk: студент гр. 3822Б1ПР2 Титов С.М.

:smiley: студент гр. 3822Б1ПР2 Мухина М.О.

## 1\. Введение

### 1.1. Наименование программы

Наименование программы: "Алгебра полиномов"

### 1.2. Назначение и область применения

Программа предназначена для работы с различными видами полиномов, которая будет осуществляться за счёт реализации операций над ними. Она будет использовать несколько видов таблиц, часто используемых в языках программирования. Система будет работать с данными различных типов, включая, но не ограничиваясь:

:white_circle: Данные предоставленный заказчиком (преподавателем). Подразумеваются готовые примеры, выбранные преподавателем для более полного тестирования правильности выполнения всех алгоритмов

:white_circle: Произвольно выбранные нами примеры, подсчёт которых может совершить самостоятельно.

:white_circle: Всевозможные наборы полиномов, с которыми может столкнуться человек решающий математическую задачу.

Программа обеспечит веб-интерфейс для удобного взаимодействия с системой. Пользователи смогут получать информацию о состоянии системы на каждом этапе её преобразования. Основная цель программы – реализации нескольких систем хранения полиномов в памяти с последующим их использованием.

## 2\. Требования к программе

Программа должна обеспечивать выполнение следующих функций:

:white_check_mark: Полиномы хранятся в виде списка.

:white_check_mark: Полиномы хранятся во всех таблицах одновременно. Ключом является имя.

:white_check_mark: Таблиц д.б. 6 видов: линейная на массиве, линейная на списке, упорядоченная на массиве, дерево (АВЛ или красно-черное), две хэш-таблицы.

:white_check_mark: Операции над отдельным полиномом: вычисление в точке, умножение на константу, производная\*, интеграл\*.

:white_check_mark: Операции в выражениях из полиномов: сложение, вычитание, умножение на константу, умножение полиномов\*, деление полиномов\*. Операции должны выполняться, используя постфиксную форму.

:white_check_mark: Операции над таблицами: добавление полинома (во все сразу), удаление полинома (во всех сразу), поиск (только в активной таблице, выполняется в процессе вычисления выражений, составленных из имен полиномов).

:white_check_mark: Активная (выбранная пользователем) таблица должна выводиться на экран в формате, как минимум, двух столбцов: 1) имя полинома, 2) строковое представление полинома.

Эти функциональные требования нацелены на обеспечение удобства пользователей при работе с системой, управлением данными и предоставлением функциональности администраторам для эффективного анализа и управления информацией.

## 3\. Краткая сводка о видах таблиц

1\. Линейная таблица на массиве:

Это простая реализация таблицы, в которой элементы хранятся в массиве и доступ к ним осуществляется по индексу.
Операции вставки и удаления могут быть неэффективными, если требуется сдвигать элементы при каждой операции.
Преимущество - простота и быстрый доступ к элементам по индексу.

2\. Линейная таблица на списке:

В этой реализации каждый элемент таблицы представляется узлом списка, соединенных между собой указателями.
Операции вставки и удаления могут быть эффективными, поскольку не требуется перемещать остальные элементы.
Однако доступ к элементам по индексу может быть медленным из-за необходимости проходить по списку от начала до нужного элемента.

3\. Упорядоченная таблица на массиве:

Эта таблица представляет собой массив элементов, отсортированных по ключу.
Поиск элемента в такой таблице может быть эффективным благодаря использованию бинарного поиска.
Однако вставка и удаление элементов могут потребовать сдвига большого количества элементов, что делает их менее эффективными.

4\. Дерево (AVL или красно-черное):

Дерево представляет собой структуру данных, в которой каждый узел имеет не более двух дочерних узлов.
В AVL-дереве и красно-черном дереве гарантируется сбалансированность, что обеспечивает эффективные операции поиска, вставки и удаления.
Эти структуры данных широко используются в реализации словарей, ассоциативных массивов и баз данных.

5\. Хэш-таблица с открытой адресацией:

Это метод реализации хэш-таблицы, в котором все элементы хранятся непосредственно в основной таблице.
При коллизии (когда два элемента хэшируются в одну ячейку) используется алгоритм поиска другой доступной ячейки.
Этот метод позволяет эффективно решать коллизии, но может привести к затратам на дополнительную память и сложностям при удалении элементов.

6\. Хэш-таблица с цепочками:

В этой реализации каждая ячейка хэш-таблицы содержит связанный список элементов, которые имеют одинаковый хэш.
При коллизии новый элемент добавляется в соответствующий список.
Этот метод прост в реализации и позволяет эффективно обрабатывать коллизии, но требует дополнительной памяти для хранения указателей на списки.

## 4\. Распределение задач внутри группы разработки

| :star: Титов Семён :star:  | :milky_way: Сорокин Андрей :milky_way: | :boom: Мухина Маргарита :boom: |                           
| -------------------------  | ----------------------------- | ------------------------- |
| 1) ListTable		           | 1) Polinom                    | 1) ListHashTable          |
| 2) Визуальный интерфейс    | 2) Базовая таблица	          | 2) OpenAddrHashTable	     |
| 3) Экперименты для отчета  | 3) ArrayTable                 | 3) SortArrayTable         |
|                            | 4) Интерфейс(менеджер таблиц) | 4) TreeTable              |
|                            | 5) ReadMe and sample          | 5) Подготовка презентации |

## 5\. Пример отработки программы

Пусть к настоящему моменту в таблицах хранятся полиномы, указанные ниже: 

```
pol1 = 3.2x²y³z - 1.3x¹z⁴  
pol2 = -3.2x²y³z + 1.3x¹z⁴  
const6 = 6.0  
q = 4.0x²
```


Пусть введено следующее выражение: `new_pol = 2 * pol1 + 2 * pol2 + 3.6 * q – const6`

Требуется:

- Найти в активной таблице все полиномы (сообщить об ошибке при необходимости).
- Сформировать новый полином, вычислив выражение. В данном случае должен получиться полином `new_pol = 14.4x2 – 6.0`.
- Добавить новый полином во все таблицы.

## 6\. Информация о загрузке и cmake

### *Windows*
To build and run this project locally on Windows, follow these steps:

1. **Clone the repository:**  
   Clone this repository to your local machine using the following command:
   ```bash
   git clone [https://github.com/embedded-dev-research/itlab_2023.git](https://github.com/Algorithms-and-data-structures-Labs/Lab_1.git)
   ```
2. **Update submodules:**
   Navigate to the project directory and update the submodules:
   ```bash
   git submodule update --init --recursive
3. **Configure the project:**
   Create a separate directory for configure the project and compile it:
   ```bash
   mkdir build
   cd build
   cmake ..
    ```
    *Note: Make sure you have CMake installed to build the project.*

## 7\. Характеристическая оценка производительности

Эксперименты проводились на ПК с следующими параметрами:

1. Операционная система: Windows 10
1. Процессор: Intel(R) Core(TM) i3-7020U CPU @ 2.30GHz   2.30 GHz
1. Версия Visual Studio: 2022

   **Алгоритмическая сложность**

|&emsp;Операция |&emsp;Неупорядоченная таблица|&emsp;Упорядоченная таблица|&emsp;Таблица на списке|&emsp;АВЛ-дерево|&emsp;Хеш-таблица с открытой адресацией |&emsp;Хеш-таблица с методом цепочек|
| - | - | - | - | - | - | - |
|&emsp;Поиск|&emsp;N|&emsp;log<sub>2</sub>N |&emsp;N|&emsp;1\.45log<sub>2</sub>N|&emsp;1|&emsp;1|
|&emsp;Вставка|&emsp;N + 1|&emsp;log<sub>2</sub>N + N|&emsp;1|&emsp;1\.45log<sub>2</sub>N + С<sub>1</sub>|&emsp;1|&emsp;1|
|&emsp;Удаление|&emsp;N + 1|&emsp;log<sub>2</sub>N + N|&emsp;N + 1|&emsp;1.45log<sub>2</sub>(N)*С<sub>2</sub>|&emsp;1|&emsp;1|

   **Вставка**

|&emsp;Количество элементов|&emsp;1000|&emsp;5000|&emsp;10000|&emsp;20000|
| :- | :-: | :- | :- | :- |
|&emsp;ArrayTable|&emsp;17|&emsp;18|&emsp;20|&emsp;22|
|&emsp;SortArrayTable|&emsp;1409|&emsp;9324|&emsp;21472|&emsp;41805|
|&emsp;ListTable|&emsp;25|&emsp;25|&emsp;28|&emsp;30|
|&emsp;ListHashTable|&emsp;23|&emsp;24|&emsp;30|&emsp;31|
|&emsp;TreeTable|&emsp;122|&emsp;536|&emsp;2307|&emsp;2310|
|&emsp;OpenAddHashTable|&emsp;15|&emsp;17|&emsp;25|&emsp;29|

   **Удаление**

|&emsp;Количество элементов|&emsp;1000|&emsp;5000|&emsp;10000|&emsp;20000|
| :- | :-: | :- | :- | :- |
|&emsp;ArrayTable|&emsp;26|&emsp;94|&emsp;190|&emsp;529|
|&emsp;SortArrayTable|&emsp;178|&emsp;826|&emsp;3004|&emsp;5098|
|&emsp;ListTable|&emsp;101|&emsp;420|&emsp;581|&emsp;1803|
|&emsp;ListHashTable|&emsp;27|&emsp;53|&emsp;78|&emsp;175|
|&emsp;TreeTable|&emsp;86|&emsp;420|&emsp;1516|&emsp;4091|
|&emsp;OpenAddHashTable|&emsp;9|&emsp;9|&emsp;12|&emsp;12|

   **Поиск**

|&emsp;Количество элементов|&emsp;1000|&emsp;5000|&emsp;10000|&emsp;20000|
| :- | :-: | :- | :- | :- |
|&emsp;ArrayTable|&emsp;23|&emsp;77|&emsp;161|&emsp;301|
|&emsp;SortArrayTable|&emsp;1|&emsp;3|&emsp;3|&emsp;4|
|&emsp;ListTable|&emsp;28|&emsp;96|&emsp;586|&emsp;1199|
|&emsp;ListHashTable|&emsp;16|&emsp;30|&emsp;71|&emsp;113|
|&emsp;TreeTable|&emsp;5|&emsp;6|&emsp;10|&emsp;11|
|&emsp;OpenAddHashTable|&emsp;6|&emsp;6|&emsp;8|&emsp;8|

   Исходя из результатов экспериментов можно сделать вывод, что по времени выполнения операций для различных структур данных:

:white_circle: Вставка:

- Самое быстрое время вставки у хеш-таблицы с открытой адресацией и хеш-таблицы с методом цепочек, а также неупорядоченной таблицы и таблицы на списке.
- Самое длительное время вставки у упорядоченной таблицы.

:white_circle: Удаление:

- Самое быстрое время удаления у хеш-таблицы с открытой адресацией.
- Самое длительное время удаления у упорядоченной таблицы.

:white_circle: Поиск:

- Самое быстрое время поиска у упорядоченной таблицы, у хеш-таблицы с открытой адресацией и хеш-таблицы с методом цепочек.
- Самое длительное время поиска у таблицы на списке и дерева.

Все эти результаты почти полностью совпадают с алгоритмической сложностью операций.
