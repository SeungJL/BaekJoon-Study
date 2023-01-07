#include<iostream>
#include<queue>
#include<string>

using namespace std;


queue<int>name;
int nameLength[21];
int N, K;
string temp;
int nameSize;
long long ans;
int main()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		nameSize = temp.length();
		name.push(nameSize);

		if (i > K)
		{
			if (nameLength[name.front()] > 0)
				nameLength[name.front()]--;
			name.pop();

		}

		nameLength[nameSize]++;
		if (nameLength[nameSize] > 0)
			ans += (nameLength[nameSize] - 1);

	}

	cout << ans;
}