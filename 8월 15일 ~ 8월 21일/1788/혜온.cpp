#include<iostream>
#include<cmath>
using namespace std;

long long Fibonacci[1000001] = { 0 };


int main()
{
	//cout << -3 % 2 << endl;
	int n;
	cin >> n;
	if (n == 0)
	{
		cout << 0 << "\n" << 0 << endl;
		return 0;
	}
	bool check = true;
	Fibonacci[0] = 0;
	Fibonacci[1] = 1;
	if (n < 0)
	{
		check = false;
		n = abs(n);
	}

	for (int i = 2; i <= n; i++)
	{
		Fibonacci[i] = (Fibonacci[i - 1] + Fibonacci[i - 2]) % 1000000000;
	}
	if (check)
		cout << 1 << "\n" << Fibonacci[n] << endl;
	else
	{
		if (n % 2 == 0)
			cout << -1 << "\n" << Fibonacci[n] << endl;
		else
			cout << 1 << "\n" << Fibonacci[n] << endl;
	}

}