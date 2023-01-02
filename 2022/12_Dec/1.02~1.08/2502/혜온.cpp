#include<iostream>

using namespace std;

int d, k;//할머니가 넘어 온 날, 떡의 개수
//6 41


int a, b;
void mountain(int day, int riceCake1, int riceCake2)
{

	if (riceCake1 < 1 || riceCake1>riceCake2)
		return;

	if (day == d)
	{
		cout << riceCake1 << "\n" << riceCake2;
		exit(0);

	}



	mountain(day + 1, riceCake2 - riceCake1, riceCake1);

}
int main()
{
	cin >> d >> k;
	for (int i = k / 2 + 1; i < k; i++)
	{

		mountain(2, i, k);

	}
}