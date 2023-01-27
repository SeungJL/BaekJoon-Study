#include<iostream>
#include<queue>

using namespace std;
int N;
priority_queue<int, vector<int>, greater<int>>q;


int main()
{
	cin >> N;
	int tmp = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		q.push(tmp);
	}
	int a = 0, b = 0;
	int sum = 0;
	//cout << endl;
	while (q.size() != 1)
	{
		a = q.top(); q.pop();
		b = q.top(); q.pop();
		sum += (a + b);
		q.push(a + b);
	}
	
	cout << sum;
}