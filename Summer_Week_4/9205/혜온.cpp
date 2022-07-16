#include<iostream>
#include<cstring>
#include<cmath>
#include<queue>

using namespace std;

int T;
int storeN, homeX, homeY, endX, endY, tempX, tempY;

int store[2][101];
bool check[101];



bool bfs()
{
	queue<pair<int, int>>road;
	road.push(make_pair(homeX, homeY));

	while (!road.empty())
	{

		int a = road.front().first;
		int b = road.front().second;

		road.pop();

		if (abs(endX - a) + abs(endY - b) <= 1000)
			return true;

		for (int i = 0; i < storeN; i++)
		{
			if (!check[i] && abs(a - store[0][i]) + abs(b - store[1][i]) <= 1000)
			{
				check[i] = true;
				road.push(make_pair(store[0][i], store[1][i]));
			}
		}




	}
	return false;

}



int main()
{

	cin >> T;

	while (T--)
	{
		memset(check, 0, sizeof(check));
		cin >> storeN;
		cin >> homeX >> homeY;
		for (int i = 0; i < storeN; i++)
		{
			cin >> store[0][i] >> store[1][i];

		}
		cin >> endX >> endY;
		if (bfs())
			cout << "happy" << "\n";
		else
			cout << "sad" << "\n";
	}
}


