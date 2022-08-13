#include<iostream>
#include<string>

using namespace std;

int N, cnt;
string s;

void Hanoi(int n, string from, string to, string via)
{
	if (n == 1)
	{
		cnt++;
		s += (from + " " + to);
		s += "\n";
		return;
	}
	else
	{
		Hanoi(n - 1, from, via, to);
		cnt++;
		s += (from + " " + to);
		s += "\n";
		Hanoi(n - 1, via, to, from);
		
	}
}

int main()
{
	cin >> N;
	Hanoi(N, "1", "3", "2");
	cout << cnt << "\n" << s;
}