#include <iostream>

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
    int value = 117;
    rec(value);
    return 0;
}