#include <iostream>

int main()
{
	int value = 83569;
	int a = 0;
	while (value > 9)
	{
		
		
		
		std::cout << value % 10 << std::endl;
		a += (value % 10);
		value = (value / 10);
		
	}
	std::cout << value << std::endl;
	std::cout << a + value << std::endl;
	return 0;
}