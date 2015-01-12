#include <iostream>
using namespace std;

#define N 9

void multiply(int a, int b)
{
	cout << a << 'x' << b << '=' << a*b << endl;
}

void qq()
{
	for (int i = 1 ; i <= N ; i++)
		for (int j = 1; j <= N; j++)
			multiply(i,j);
}

int main()
{
	qq();
	return 0;
}