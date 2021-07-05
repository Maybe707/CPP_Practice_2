#include <iostream>

int getNumber()
{
    std::cout << "Enter number: " << std::endl;
    int numb1;
    std::cin >> numb1;
    return numb1;
}

char getSymbol()
{
    char sym;
    do
    {
        std::cout << "Enter operation: " << std::endl;
        std::cin >> sym;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }

    }while(sym != '+' && sym != '-' && sym != '*' && sym != '/');
    return sym;
}

int add(int a, int b)
{
    return a + b;
}

int substract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    return a / b;
}

typedef int(*arithmeticFcn)(int, int);

arithmeticFcn getArithmeticFcn(char sym)
{
    switch(sym)
    {
        case '+': return add;
        case '-': return substract;
        case '*': return multiply;
        case '/': return divide;
    }
}

int main()
{
    int number1 = getNumber();
    char symbol = getSymbol();
    int number2 = getNumber();
    arithmeticFcn ptr;
    ptr = getArithmeticFcn(symbol);
    std::cout << ptr(number1, number2) << std::endl;
    return 0;
}