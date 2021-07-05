#include <iostream>
#include <cassert>

class Stack
{
private:
    int array[10];
    int arrayCount = 0;
public:
    void reset()
    {
        for(int count = 0; count < 10; ++count)
        {
            array[count] = 0;
        }
        arrayCount = 0;
    }

    bool push(int stackNumb)
    {
        if(arrayCount <= 10)
        {
            array[arrayCount] = stackNumb;
            ++arrayCount;
            return true;
        }
        return false;
    }

    void pop()
    {
        assert(arrayCount != 0 && "Stack is empty. ");
        if(arrayCount != 0)
        {
            array[arrayCount-1] = 0;
            --arrayCount;
        }
    }

    void print()
    {
        std::cout << "( ";
        for(int count = 0; count < 10; ++count)
        {
            if(array[count] != 0)
            {
                std::cout << array[count] << " ";
            }
        }
        std::cout << ")";
        std::cout << std::endl;
    }
};

int main()
{
    Stack stack;
    stack.reset();

    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();

    stack.print();

    return 0;
}