#include <iostream>
#include <cmath>
using namespace std;
int f(int n,int level,int &depth)
{
	if (level > depth)
		depth = level;
	if (n == 1)
		return 1;
	if (n % 2 == 0)
		return (2 * f(n / 2,level + 1,depth) - 1);
	else
		return (2 * f(n / 2,level + 1,depth) + 1);
}

int main()
{
	int n, depth;
	cout << "n= "; cin >> n;
	cout <<"x=" << f(n,1,depth) << endl;
	cout << "Kp=" << n - 1 << endl;
	while (true)
	{
		n = f(n,1,depth);
		if (n == f(n,1,depth))
		{
				cout << "y =" << f(n,1,depth) << endl;
				break;
		}
	}
	
	cout << "depth=" << depth << endl;
	return 0;
}