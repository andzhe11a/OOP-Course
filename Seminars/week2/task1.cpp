#include <iostream>

struct Person
{
    char name[25];
    int age;
    char gender;
};

void inputPeople(Person people[], int size)
{
    std::cin.ignore();
    for (int i = 0; i < size; i++)
    {
        std::cout << "Enter name: ";
        std::cin.getline(people[i].name, 25);

        std::cout << "Enter age: ";
        std::cin >> people[i].age;

        std::cout << "Enter gender (M/F): ";
        std::cin >> people[i].gender;

        std::cin.ignore();
    }
}

void printPerson(const Person& person)
{
    std::cout << person.name << ", " << person.age << " years old" << std::endl;
}

void printMen(Person people[], int size)
{
    std::cout << "\nAll men: " << std::endl;
    for (int i = 0; i < size; i++)
    {
        if (people[i].gender == 'M' || people[i].gender == 'm')
        {
            printPerson(people[i]);
        }
    }
}

void printWomen(Person people[], int size)
{
    std::cout << "\nAll women: " << std::endl;
    for (int i = 0; i < size; i++)
    {
        if (people[i].gender == 'F' || people[i].gender == 'f')
        {
            printPerson(people[i]);
        }
    }
}

Person findOldestWoman(const Person people[], int size)
{
    Person oldestWoman = {"", -1, 'F'};

    for (int i = 0; i < size; i++)
    {
        if ((people[i].gender == 'F' || people[i].gender == 'f') && people[i].age > oldestWoman.age)
        {
            oldestWoman = people[i];
        }
    }
    return oldestWoman;
}

Person findYoungestManWithA(const Person people[], int size)
{
    Person youngestManWithA = {"", 200, 'M'};

    for (int i = 0; i < size; i++)
    {
        if ((people[i].gender == 'M' || people[i].gender == 'm') && (people[i].name[0] == 'A' || people[i].name[0] == 'a') && people[i].age < youngestManWithA.age)
        {
            youngestManWithA = people[i];
        }
    }
    return youngestManWithA;
}

int main()
{
    int size;
    std::cout << "Enter the number of people: ";
    std::cin >> size;
    std::cin.ignore();

    Person* people = new Person[size];

    inputPeople(people, size);

    printMen(people, size);
    printWomen(people, size);

    Person oldestWoman = findOldestWoman(people, size);
    if (oldestWoman.age != -1)
    {
        std::cout << "\nOldest woman: ";
        printPerson(oldestWoman);
    }

    Person youngestManWithA = findYoungestManWithA(people, size);
    if (youngestManWithA.age != 200)
    {
        std::cout << "Youngest man with name starting with 'A': ";
        printPerson(youngestManWithA);
    }
    else
    {
        std::cout << "No men with name starting with 'A'.\n";
    }

    delete[] people;

    return 0;
}
