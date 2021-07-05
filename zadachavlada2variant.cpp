#include <iostream>
using namespace std;
const int N = 30;
int main()
{
	long a[N];
	long i, j = 0, k[30];
	for (i = 0; i < N; i++)
	{
		cout << "Enter a number: " << endl;
		cin >> a[i];
	}
	
	for (i = 0; i < N; i++)
	{
		if (a[i] > 100)
		{
			if ((a[i] % 4) != 0)
			{
				k[j] = i;
				j++;
			}
		}
	}

	for (i = 0; i < j; i++)
	{
		a[k[i]] = j;
	}

	for (i = 0; i < N; i++)
	{
		std::cout << a[i] << std::endl;
	}

	return 0;
}