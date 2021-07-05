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

        std::cout << "Enter operation: " << std::endl;
        char sym;

        do
        {
            std::cin >> sym;
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }
        }while(sym != '+' && sym != '-' && sym != '*' && sym != '/');
    switch(sym)
    {
        case '+': return sym;
        case '-': return sym;
        case '*': return sym;
        case '/': return sym;
    }
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

struct arithmeticStruct
{
    char symbolic;
    arithmeticFcn pointer;
};

static arithmeticStruct array[]
        {
                { '+', add },
                { '-', substract },
                { '*', multiply },
                { '/', divide }
        };

arithmeticFcn getArithmeticFcn(char sym)
{
    for(arithmeticStruct value: array)
    {
        if(value.symbolic == sym)
        return value.pointer;
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