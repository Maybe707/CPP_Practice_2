#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <algorithm>

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    // Равномерно распределяем рандомное число в нашем диапазоне
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

int main(int argc, char *argv[]) {
    std::cout << "Enter plz random number noooooob: " << std::endl;
    int startNumb;
    std::cin >> startNumb;

    std::cout << "Enter another number nooobazz: " << std::endl;
    int countNumb;
    std::cin >> countNumb;

    // Генерируем рандомное число от 2 до 4.

    srand(static_cast<unsigned int>(time(0))); // устанавливаем значение системных часов в качестве стартового числа
    rand();
    int randomNumb = getRandomNumber(2, 4);

    std::cout << "I generated " << countNumb << " square numbers." <<
              " Do you know what each number is after multiplying it by " << randomNumb << std::endl;

    std::vector<int> array{startNumb};
    array.resize(countNumb);

    for (int count = 0; count < countNumb; ++count)
    {
        array[count] = ((startNumb + count) * (startNumb + count)) * randomNumb;
        std::cout << array[count] << std::endl;
    }

    int value;
    std::cin >> value;

    auto found{std::find(array.begin(), array.end(), value)};

    if (found != array.end()) {
        array.erase(found);
    }

    auto best{
            std::min_element(array.begin(), array.end(), [value](const auto &a, const auto &b) {
                int distance1{std::abs(a - value)}; // 2
                int distance2{std::abs(b - value)}; // 2
                std::cout << a << " " << b << std::endl;
                std::cout << distance1 << " <" << distance2 << std::endl;
                return (distance1 < distance2);
            })
    };

    if (std::abs(value - *best) <= 4)
    {
        std::cout << value << " is wrong!" << " Try" << *best << " next time" << std::endl;
    }
    else
        {
            std::cout << value << " is wrong!" << std::endl;
        }
}
