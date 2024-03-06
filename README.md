МИНИСТЕРСТВО ОБРАЗОВАНИЯ И НАУКИ РОССИЙСКОЙ ФЕДЕРАЦИИ

Федеральное государственное автономное образовательное учреждение высшего образования

**«Нижегородский государственный университет им. Н.И. Лобачевского»**

**Национальный исследовательский университет**

**Институт информационных технологий, математики и механики**

**Кафедра математического обеспечения и суперкомпьютерных технологий**

**Лабораторная работа №1 "Алгебра полиномов"**

Техническое задание

00378249.000.001.ТЗ.01.1-1



Листов &lt;9&gt;

Исполнители,

студент гр. 3822Б1ПР2 Сорокин А.А.

студент гр. 3822Б1ПР2 Титов С.М.

студент гр. 3822Б1ПР2 Мухина М.О.

2023

# 1\. Введение

# 1.1. Наименование программы

Наименование программы: "Алгебра полиномов"

# 1.2. Назначение и область применения

Программа предназначена для работы с различными видами полиномов, которая будет осуществляться за счёт реализации операций над ними. Она будет использовать несколько видов таблиц, часто используемых в языках программирования. Система будет работать с данными различных типов, включая, но не ограничиваясь:

1.2.1.Данные предоставленный заказчиком (преподавателем). Подразумеваются готовые примеры, выбранные преподавателем для более полного тестирования правильности выполнения всех алгоритмов

1.2.2.Произвольно выбранные нами примеры, подсчёт которых может совершить самостоятельно.

1.2.3.Всевозможные наборы полиномов, с которыми может столкнуться человек решающий математическую задачу.

Программа обеспечит веб-интерфейс для удобного взаимодействия с системой. Пользователи смогут получать информацию о состоянии системы на каждом этапе её преобразования. Основная цель программы – реализации нескольких систем хранения полиномов в памяти с последующим их использованием.

# 2\. Требования к программе

# 2.1. Требования к функциональным характеристикам

Программа должна обеспечивать выполнение следующих функций:

2.1.1. Полиномы хранятся в виде списка.

2.1.2. Полиномы хранятся во всех таблицах одновременно. Ключом является имя.

2.1.3. Таблиц д.б. 6 видов: линейная на массиве, линейная на списке, упорядоченная на массиве, дерево (АВЛ или красно-черное), две хэш-таблицы.

2.1.4. Операции над отдельным полиномом: вычисление в точке, умножение на константу, производная\*, интеграл\*.

2.1.5. Операции в выражениях из полиномов: сложение, вычитание, умножение на константу, умножение полиномов\*, деление полиномов\*. Операции должны выполняться, используя постфиксную форму.

2.1.6. Операции над таблицами: добавление полинома (во все сразу), удаление полинома (во всех сразу), поиск (только в активной таблице, выполняется в процессе вычисления выражений, составленных из имен полиномов).

2.1.7. Активная (выбранная пользователем) таблица должна выводиться на экран в формате, как минимум, двух столбцов: 1) имя полинома, 2) строковое представление полинома.

Эти функциональные требования нацелены на обеспечение удобства пользователей при работе с системой, управлением данными и предоставлением функциональности администраторам для эффективного анализа и управления информацией.

# 2.2. Требования к надежности

# 2.2.1. Требования к обеспечению надежного функционирования программы

Для обеспечения надежного и устойчивого функционирования программы необходимо выполнение следующих организационно-технических мероприятий заказчиком:

а) Обеспечение бесперебойного питания технических средств, чтобы минимизировать риск возможных сбоев и потерь данных.

б) Использование лицензионного программного обеспечения для обеспечения соблюдения юридических норм и предотвращения возможных проблем, связанных с нелицензионным ПО.

в) Регулярное выполнение рекомендаций Министерства труда и социального развития РФ, изложенных в Постановлении от 23 июля 1998 года 'Об утверждении межотраслевых типовых норм времени на работы по сервисному обслуживанию ПЭВМ и оргтехники и сопровождению программных средств', для обеспечения надлежащего обслуживания программной системы.

г) Регулярное выполнение требований стандарта ГОСТ 51188-98 'Защита информации. Испытания программных средств на наличие компьютерных вирусов' для проверки наличия компьютерных вирусов в программном обеспечении, обеспечивая безопасность и непрерывную работу системы рекомендаций.

# 2.2.2. Время восстановления после отказа

Время восстановления после отказа, вызванного сбоем электропитания технических средств (иными внешними факторами), не фатальным сбоем (не крахом) операционной системы, не должно превышать 30-ти минут при условии соблюдения условий эксплуатации технических и программных средств.  
Время восстановления после отказа, вызванного неисправностью технических средств, фатальным сбоем (крахом) операционной системы, не должно превышать времени, требуемого на устранение неисправностей технических средств и переустановки программных средств.

# 2.2.3. Отказы из-за некорректных действий пользователей системы

Отказы программы вследствие некорректных действий пользователя при взаимодействии с программой возможны при попытке вызвать функционал не допустимый при обычной работе программы. Данные ошибки будут сопровождаться исключениями, которые будут предусмотрены и описаны командой программистов. В следствие частого возникновения определённого рода ошибок будут выдвинуты фиксы.

# 3\. Условия эксплуатации

# 3.1. Климатические условия эксплуатации

Климатические условия эксплуатации, при которых должны обеспечиваться заданные характеристики, должны удовлетворять требованиям, предъявляемым к техническим средствам в части условий их эксплуатации

# 3.2. Требования к квалификации и численности персонала

Минимальное количество персонала, требуемого для работы программы, должно составлять не менее 1 штатной единицы — конечный пользователь программы — оператор. Интерфейс будет предельно понятен каждому человеку, который имеет некоторый опыт в работе с программами, поэтому в данном случае не требуется привлечение дополнительного персонала. Но для дальнейшего усовершенствования данной программы, включающего, как исправление недочётов, так и введение новых функций, будет необходима команда из 2-3 человек, для оперативной работы.

# 3.3. Требования к составу и параметрам технических средств

Технические характеристики сервера должны соответствовать следующим параметрам:

3.3.1.1. Процессор с тактовой частотой не менее 2.0 Гигагерц.

3.3.1.2. Объем оперативной памяти не менее 1 Гигабайта.

3.3.1.3. Жесткий диск (HDD) емкостью не менее 40 Гигабайт.

3.3.1.4. Операционная система должна быть Windows 10/11.

3.3.1.5. Для обеспечения безопасности и стабильной работы программы требуется использование лицензионного программного обеспечения.

# 3.4. Требования к информационной и программной совместимости

# 3.4.1. Требования к информационным структурам и методам решения

Таблиц д.б. 6 видов: линейная на массиве, линейная на списке, упорядоченная на массиве, дерево (АВЛ или красно-черное), две хэш-таблицы. Все данные виды структур должны быть реализованы в коде программы, а их работоспособность должна подтверждаться тестами.

# 3.4.2. Требования к исходным кодам и языкам программирования

Дополнительные требования не предъявляются.

# 3.4.3. Требования к программным средствам, используемым программой

Системные программные средства, используемые программой, должны быть представлены лицензионной локализованной версией операционной системы Windows 10/11 и Visual Studio 2022.

# 3.4.4. Требования к защите информации и программ

Требования к защите информации и программ не предъявляются.

# 3.5. Специальные требования

Программа должна обеспечивать не только обязательный перечень операций, но и включать определённый набор дополнительный операций, которые будет выбирать сама команда разработчиков.

# 4\. Требования к программной документации

Состав программной документации должен включать в себя:  
4.1. техническое задание;  
4.2. программу и методики испытаний;

# 5\. Технико-экономические показатели

# 5.1. Экономические преимущества разработки

Ориентировочная экономическая эффективность не рассчитываются. Аналогия не проводится ввиду уникальности предъявляемых требований к разработке.

#

# 6\. Стадии и этапы разработки

# 6.1. Стадии разработки

Разработка должна быть проведена в четыре стадии:  
1\. разработка технического задания;  
2\. рабочее проектирование;

3\. тестирование;  
4\. внедрение.

# 6.2. Этапы разработки

На стадии разработки технического задания должен быть выполнен этап разработки, согласования и утверждения настоящего технического задания.  
На стадии рабочего проектирования должны быть выполнены перечисленные ниже этапы работ:

1\. разработка программы;  
2\. разработка программной документации;  
3\. испытания программы.

На стадии внедрения должен быть выполнен этап разработки подготовка и передача программы.

# 6.3. Содержание работ по этапам

На этапе разработки технического задания должны быть выполнены перечисленные ниже работы:  
1\. постановка задачи;  
2\. определение и уточнение требований к техническим средствам;  
3\. определение требований к программе;  
4\. определение стадий, этапов и сроков разработки программы и документации на неё;  
5\. согласование и утверждение технического задания.  
На этапе разработки программы должна быть выполнена работа по программированию (кодированию) и отладке программы.  
На этапе разработки программной документации должна быть выполнена разработка программных документов в соответствии с требованиями к составу документации.  
На этапе испытаний программы должны быть выполнены перечисленные ниже виды работ:  
1\. разработка, согласование и утверждение и методики испытаний;  
2\. проведение приемо-сдаточных испытаний;  
3\. корректировка программы и программной документации по результатам испытаний.  
На этапе подготовки и передачи программы должна быть выполнена работа по подготовке и передаче программы и программной документации в эксплуатацию на объектах Заказчика.

# 7\. Порядок контроля и приемки

# 7.1. Виды испытаний

Приемо-сдаточные испытания должны проводиться на объекте Заказчика в оговоренные сроки.  
Приемо-сдаточные испытания программы должны проводиться согласно разработанной Исполнителем и согласованной Заказчиком Программы и методик испытаний.  
Ход проведения приемо-сдаточных испытаний Заказчик и Исполнитель документируют в Протоколе проведения испытаний

# 7.2. Общие требования к приемке работы

На основании Протокола проведения испытаний Исполнитель совместно с Заказчиком подписывает Акт приемки-сдачи программы в эксплуатацию

# 8\. Приложение

# 8.1. Виды таблиц
1\.Линейная таблица на массиве:

Это простая реализация таблицы, в которой элементы хранятся в массиве и доступ к ним осуществляется по индексу.
Операции вставки и удаления могут быть неэффективными, если требуется сдвигать элементы при каждой операции.
Преимущество - простота и быстрый доступ к элементам по индексу.

2\.Линейная таблица на списке:

В этой реализации каждый элемент таблицы представляется узлом списка, соединенных между собой указателями.
Операции вставки и удаления могут быть эффективными, поскольку не требуется перемещать остальные элементы.
Однако доступ к элементам по индексу может быть медленным из-за необходимости проходить по списку от начала до нужного элемента.

3\.Упорядоченная таблица на массиве:

Эта таблица представляет собой массив элементов, отсортированных по ключу.
Поиск элемента в такой таблице может быть эффективным благодаря использованию бинарного поиска.
Однако вставка и удаление элементов могут потребовать сдвига большого количества элементов, что делает их менее эффективными.

4\.Дерево (AVL или красно-черное):

Дерево представляет собой структуру данных, в которой каждый узел имеет не более двух дочерних узлов.
В AVL-дереве и красно-черном дереве гарантируется сбалансированность, что обеспечивает эффективные операции поиска, вставки и удаления.
Эти структуры данных широко используются в реализации словарей, ассоциативных массивов и баз данных.

5\.Хэш-таблица с открытой адресацией:

Это метод реализации хэш-таблицы, в котором все элементы хранятся непосредственно в основной таблице.
При коллизии (когда два элемента хэшируются в одну ячейку) используется алгоритм поиска другой доступной ячейки.
Этот метод позволяет эффективно решать коллизии, но может привести к затратам на дополнительную память и сложностям при удалении элементов.

6\.Хэш-таблица с цепочками:

В этой реализации каждая ячейка хэш-таблицы содержит связанный список элементов, которые имеют одинаковый хэш.
При коллизии новый элемент добавляется в соответствующий список.
Этот метод прост в реализации и позволяет эффективно обрабатывать коллизии, но требует дополнительной памяти для хранения указателей на списки.

7\.Две хэш-таблицы:

Это метод, включающий использование двух различных хэш-функций и двух таблиц для хранения данных.
При вставке элемента сначала используется первая хэш-функция, чтобы определить индекс в первой таблице. Если в этой ячейке уже есть элемент, применяется вторая хэш-функция для размещения элемента во второй таблице.
Этот метод может уменьшить вероятность коллизий и улучшить производительность операций, но требует дополнительной памяти.