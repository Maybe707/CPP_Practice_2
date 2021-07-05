#include <iostream>

int rec(int value, bool flag)
{
    if (value < 0)
    {
        value = (-value);
    }
    if (value == 0)
    {
        std::cout << value << " is zero " << std::endl;
        return value;
    }
    int rem = value % 2;

    // Проверка.

    if (rem == 1)
    {
        if (flag)
        {
            rem = 0;
            flag = false;
        }
    }
    if (rem == 0)
    {
        if (flag)
        {
            rem = 1;
        }
    } 

    if (value < 2)
    {
        if (value == 1)
        {
            value = 0;
            std::cout << !rem << " ";
            return value;
        }
        std::cout << value << std::endl;
        return value;
    }
    rec(value / 2, flag);
    std::cout << !rem << " ";
}

int rec(int value)
{
    int rem = value % 2;
    if (value < 2)
    {
        std::cout << value << std::endl;
        return value;
    }
    rec(value / 2);
    std::cout << rem << std::endl;
}

int main()
{
    bool flag = true;
    std::cout << "Enter a number: " << std::endl;
    int value;
    std::cin >> value;
    if (value < 0)
    {
        rec(value, flag);
    }
    if (value >= 0)
    {
        rec(value);
    }
    return 0;
}