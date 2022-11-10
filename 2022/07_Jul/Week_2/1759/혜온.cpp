#include<iostream>
#include<algorithm>

using namespace std;


int L, C, cntV;
char alpa[15];
bool check[15];
char temp;
//0~26
//  뽑는다 (오름차순)/ 개수 체크
char ans[15];
void backtracking(int depth, int index)
{

	if (depth == L)
	{
		cntV = 0;
		for (int i = 0; i < L; i++)
		{
			if (ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' || ans[i] == 'o' || ans[i] == 'u')
				cntV++;

		}
		if (cntV < 1 || L - cntV < 2)
			return;
		for (int i = 0; i < L; i++)
			cout << ans[i];
		cout << "\n";
		return;
	}

	for (int i = index; i < C; i++)
	{

		if (!check[i])
		{
			check[i] = true;
			ans[depth] = alpa[i];
			temp = alpa[i];

			backtracking(depth + 1, i + 1);
			check[i] = false;
		}

	}

}

int main()
{

	cin >> L >> C;
	for (int i = 0; i < C; i++)
	{
		cin >> alpa[i];
	}
	sort(alpa, alpa + C);

	backtracking(0, 0);
	

}