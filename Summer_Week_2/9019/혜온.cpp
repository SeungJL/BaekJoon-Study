#include<iostream>
#include<string>
#include<queue>
#include <cstring>
using namespace std;




int a, b;
bool visited[10000];

int T;





void bfs()	//너비 우선 탐색
{
	queue<pair<int, string>>q;
	q.push(make_pair(a, ""));
	visited[a] = true;

	while (!q.empty())
	{
		int a_temp = q.front().first;
		string a_s = q.front().second;

		q.pop();
		if (a_temp == b)
		{

			cout << a_s << "\n";
			return;
		}


		int D, S, L, R;
		//D
		D = (a_temp * 2) % 10000;
		if (!visited[D])
		{
			visited[D] = true;
			q.push(make_pair(D, a_s + "D"));
		}
		//S

		/*if (a_temp == 0)
			a_temp = 10000;*/
		S = a_temp - 1;
		if (S < 0)
			S = 9999;

		if (!visited[S])
		{
			visited[S] = true;
			q.push(make_pair(S, a_s + "S"));
		}
		//L
		/*string a_string=to_string(a_temp);
		a_string.push_back(a_string[0]);
		a_string.erase(0, 1);
		L = stoi(a_string);*/
		L = (a_temp % 1000) * 10 + (a_temp / 1000);
		if (!visited[L])
		{
			visited[L] = true;
			q.push(make_pair(L, a_s + "L"));
		}
		//R
		/*string a_string2 = to_string(a_temp);
		a_string2 = a_string2[a_string2.length() - 1] + a_string2;
		a_string2.pop_back();
		R = stoi(a_string2);*/
		R = a_temp / 10 + (a_temp % 10) * 1000;
		if (!visited[R])
		{
			visited[R] = true;
			q.push(make_pair(R, a_s + "R"));
		}


	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//cout << stoi("0001")<< "  "<<stoi("0001")+1;
	cin >> T;

	while (T--)
	{

		cin >> a >> b;
		memset(visited, false, sizeof(visited)); // 초기화

		if (a != b)
			bfs();


	}
	return 0;
}