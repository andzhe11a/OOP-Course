Задача 22. Да се реализира шаблон на абстрактен базов клас
MathExpression<T>, описващ математически израз от тип T. Класът да дефинира
метод T value() const, намиращ числовата стойност на израза и метод void
print() const, отпечатващ израза на екрана.

а) Да се дефинира реализация Constant<T>, която представя константа от
тип T. Стойността на константата да се задава при конструиране на обекта.

б) Да се дефинира реализация Max<T>, която представя максимума на
най-много 10 произволни израза от тип T. Класът да реализира метод за добавяне
на израз, като се предполага, че броят на добавените изрази няма да надхвърля 10.
При конструиране на обекти се смята, че те не съдържат никакви изрази и в този
случай максимумът по дефиниция е 0.

в) Да се дефинира реализация Average<T>, която представя средното
аритметично на най-много 10 произволни израза от тип T. Класът да реализира
метод за добавяне на израз, като се предполага, че броят на добавените изрази
няма да надхвърля 10. При конструиране на обекти се смята, че те не съдържат
никакви изрази и в този случай средното аритметично по дефиниция е 0.

г) Да се дефинира реализация Sum<T>, която представя сумата на два
произволни израза. Самите изрази да се подават по подходящ начин при
конструиране на обекти от клас Sum<T>.

д) Да се дефинира реализация Prod<T>, която представя произведението на
два произволни израза. Самите изрази да се подават по подходящ начин при
конструиране на обекти от клас Prod<T>.
