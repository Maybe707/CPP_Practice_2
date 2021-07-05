#include <iostream>
using namespace std;
const int N = 30;
int main()
{
	long a[N];
	long i, j, k;
	for (i = 0; i < N; i++)
	{
		cout << "Enter a number: " << endl;
		cin >> a[i];
	}
	int valueCounter = 0;
	int array[30];
	for (j = 0; j < N; j++)
	{
		if (a[j] > 100)
		{
			if ((a[j] % 4) != 0)
			{
				array[valueCounter] = j;
				valueCounter++;
			}
		}
	}

	for (k = 0; k < valueCounter; k++)
	{
		a[array[k]] = valueCounter;
	}

	int counter;

	for (counter = 0; counter < N; counter++)
	{
		std::cout << a[counter] << std::endl;
	}

	return 0;
}