#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int N, K;
bool aToZ[26];
bool temp[26];
bool check[26];
string s[51];
int psb, cnt, maxN;
int r;
bool visit = false;
void wordCount()
{
	cnt = 0;
	for (int i = 0; i < N; i++)
	{
		if (s[i].length() == 8)
		{
			cnt++;
			continue;
		}
		for (int j = 4; j < s[i].length() - 4; j++)
		{
			if (!check[s[i][j] - 'a'])
			{
				break;
			}
			if (j == s[i].length() - 5)
			{

				cnt++;
			}
		}
	}


}

void backtracking(int depth, int index)
{

	if (depth == psb)//||(r==25&&!visit))
	{

		wordCount();

		if (cnt > maxN)
			maxN = cnt;


		return;
	}
	for (int i = index; i < 26; i++)
	{
		if (!check[i])
		{

			r = i;
			check[i] = true;

			backtracking(depth + 1, i + 1);
			check[i] = false;




		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	if (K < 5)
	{
		cout << 0;
		return 0;
	}

	int end;

	check['a' - 'a'] = true;
	check['n' - 'a'] = true;
	check['t' - 'a'] = true;
	check['i' - 'a'] = true;
	check['c' - 'a'] = true;

	for (int i = 0; i < N; i++) {
		cin >> s[i];
		end = s[i].length() - 4;


	}
	psb = K - 5;

	//psb개를 뽑기
	backtracking(0, 0);
	cout << maxN;
}
