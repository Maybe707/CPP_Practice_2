#include <iostream>
#include <string>
#include <algorithm>

struct Person
{
    std::string name;
    int score;
};

int main()
{
    std::cout << "How many students will be in yout class? " << '\n';
    int studCount;
    std::cin >> studCount;
    Person *pointer = new Person[studCount];
    for(int count = 0; count < studCount; ++count)
    {
        std::cout << "Enter a name " << '\n';
        std::cin >> pointer[count].name;
        std::cout << "Enter score " << '\n';
        do
        {
            std::cin >> pointer[count].score;
            if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
            {
                std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
                std::cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера
            }
        }while(pointer[count].score<0 || pointer[count].score>100);
    }

    for(int count = 0; count < studCount; ++count)
    {

        for(int count2 = count+1; count2 < studCount; ++count2)
        {
            if(pointer[count2].score > pointer[count].score)
            {
               Person pers = pointer[count];
               pointer[count] = pointer[count2];
               pointer[count2] = pers;
            }

        }

    }

    for(int count3 = 0; count3 < studCount; ++count3)
    {
        std::cout << pointer[count3].name << '\n' << pointer[count3].score << '\n';
    }

    delete[] pointer;
    pointer = nullptr;
    return 0;
}