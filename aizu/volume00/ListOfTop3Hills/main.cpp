#include <iostream>
using namespace std;

int height[3];

void init()
{
	for (int i = 0; i < 3; ++i)
	{
		height[i] = 0;
	}
}

void input()
{
	int h;
	while (cin >> h){
		if (height[2] < h) height[2] = h;
		if (height[1] < h){
			height[2] = height[1];
			height[1] = h;
		}
		if (height[0] < h)
		{
			height[1] = height[0];
			height[0] = h;
		}
	}	
}

void output()
{
	cout << height[0] << endl;
	cout << height[1] << endl;
	cout << height[2] << endl;
}

int main()
{
	init();
	input();
	output();
	return 0;
}