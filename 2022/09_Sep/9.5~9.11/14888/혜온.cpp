#include<iostream>

using namespace std;
int n, sum, maxN = -10000000001, minN = 10000000001;
int num[101];
int arr[100];
// 덧셈(+)의 개수, 뺄셈(-)의 개수, 곱셈(×)의 개수, 나눗셈(÷)
//int pluss, subtract, times, division;
int op[4];


void calculation()
{
	sum = num[0];
	for (int i = 0; i < n - 1; i++)
	{
		switch (arr[i])
		{

		case 0://덧셈
		{
			sum += num[i + 1];
			break;
		}
		case 1://뺄셈
		{
			sum -= num[i + 1];
			break;
		}
		case 2://곱셈
		{
			sum *= num[i + 1];
			break;

		}
		case 3://나눗셈
		{
			sum /= num[i + 1];
			break;

		}
		}


	}
	//cout << sum;

}

void backtracking(int depth)
{
	if (depth == n - 1)
	{

		calculation();
		if (sum > maxN)
		{
			maxN = sum;
		}
		if (sum < minN)
		{
			minN = sum;
		}

	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			if (op[i] > 0)
			{
				arr[depth] = i;
				op[i]--;
				backtracking(depth + 1);
				op[i]++;
			}
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	cin >> op[0] >> op[1] >> op[2] >> op[3];

	backtracking(0);
	cout << maxN << "\n" << minN;
}
