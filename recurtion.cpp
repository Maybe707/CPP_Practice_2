#include <iostream>

int rec(int value)
{
    if(value > 9)
    {
        return rec(value / 10)+(value % 10);
    }
    return value;
}

int main()
{
    int value = 83569;
    std::cout << rec(value);
    return 0;
}