#include<iostream>
#include<queue>

using namespace std;

int n, m, tmp;
long long a, b, c, sum;
priority_queue<long long, vector<long long>, greater<long long>>q;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		q.push(tmp);
	}

	for (int i = 0; i < m; i++)
	{
		a = q.top(); q.pop();
		b = q.top(); q.pop();
		c = a + b;
		q.push(c);
		q.push(c);
	}
	for (int i = 0; i < n; i++)
	{
		sum += q.top(); q.pop();
	}
	cout << sum;
}