# Задача 1
Да се реализира клас триъгълник, който се описва чрез трите си страни. Да се реализират нужните селектори(getters) и мутатори(setters) и да се реализират методи за намиране на лице, намиране на периметър и намиране на радиус на вписана и описана окръжност.  
```math
R = \frac{abc}{4\sqrt{s(s-a)(s-b)(s-c)}}
```
```math
r = \frac{\sqrt{s(s-a)(s-b)(s-c)}}{s}
```

# Задача 2
Създайте клас, който описва кръг. Нека този клас има полета за радиус и разпложение на центъра в една декартова координатна система. След задаване на полетата, може да се променя само местоположението на кръга.

Нека се реазлизира метод, който по подадни координати, посочва дали точка се намира в кръга.

# Задача 3
Създайте клас предмет, който се състои от студенти и да се води от учител. Нека се състои от най-много 100 студенти. Нека той има метод добавяне на студент и за назначаване на учител. Напишете нужните според вас конструктори. За да запазите тази информация запишете информацията за предмета във файл с метод `serializе(const char* destinationFile)` и го прочетете от файла с метод `deserialize(const char* sourceFile)`. Използвайте .csv формата за писане и четене на информация.

Един студент има първо и последно име, и факултетен номер(който е уникален). Той има оценки, които са не повече от 32 на брой. Всеки студент трябва да има методи за добавяне и премахване на оценки, както и за пресмятането на средния успех.

Един учител има първо и последно име, както и катедра в която преподава. Нека възможните катедри са 3:
`Algebra`, `Geometry`, `Computer Science`.

Трябва да могат да се достъпват полетата на всеки клас, като това да не позволява тяхната външна промяна.

> Начина на форматиране на файла е по ваш избор, стига всяка стойност да е реазделена със запетайки

> Работете само със стекова памет
