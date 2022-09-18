#include<iostream>
#include<string>
#include<cmath>

using namespace std;

bool remocon[10];
string s;
int N, cnt;
int brokenN;
int sum = 1000000000, minT = 1000000000;

int ans = 0;
bool ok = false;

string temp;
void checkUp(int n)
{
	cnt = 0;
	for (int i = n; i < 10000001; i++) {//500000  //0 2 3 4 6 7 8 9   30000  40000 40001
		temp = to_string(i);

		ok = false;
		for (int j = temp.length() - 1; j >= 0; j--)//6 7 8    5457
		{

			if (remocon[temp[j] - '0'])
			{

				cnt++;
				ok = true;
				break;
			}

		}
		if (!ok)
		{

			sum = cnt + temp.length();

			return;
		}

	}
}
void checkDown(int n)
{
	cnt = 0;
	for (int i = n; i >= 0; i--) {//500000  //0 2 3 4 6 7 8 9   30000  40000 40001
		temp = to_string(i);
		ok = false;
		for (int j = temp.length() - 1; j >= 0; j--)
		{

			if (remocon[temp[j] - '0'])
			{
				cnt++;
				ok = true;
				break;
			}


		}
		if (!ok)
		{

			sum = cnt + temp.length();

			return;
		}

	}
}

int main()
{
	cin >> N;
	cin >> brokenN;
	if (brokenN == 0)
	{

		if (abs(100 - N) < to_string(N).length())
			cout << abs(100 - N);
		else
			cout << to_string(N).length();
		return 0;
	}
	int t = 0;
	while (brokenN--)
	{
		cin >> t;
		remocon[t] = true;
	}

	if (t == 10)//+나 -밖에 못하면
	{
		cout << abs(N - 100);
		//cout << "ddff" << endl;
		return 0;
	}
	//채널을 돌릴 필요가 없으면
	if (N == 100)
	{
		cout << 0 << endl;
		return 0;
	}

	checkDown(N);
	if (sum < minT)
	{
		minT = sum;
		//cout << "11" << endl;
	}
	checkUp(N);
	if (sum < minT)
	{
		minT = sum;
		//cout << "22" << endl;
	}
	//cout << abs(100 - N) << "    ss"<<endl;
	if (abs(100 - N) < minT)
	{
		minT = abs(100 - N);
		//cout << "dfs" << endl;
	}

	cout << minT;
}