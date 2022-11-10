#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int num[4001];
int Mnum[4001];
double sum;
vector<int>v;
int main()
{

	/*첫째 줄에는 산술평균을 출력한다.소수점 이하 첫째 자리에서 반올림한 값을 출력한다.

		둘째 줄에는 중앙값을 출력한다.

		셋째 줄에는 최빈값을 출력한다.여러 개 있을 때에는 최빈값 중 두 번째로 작은 값을 출력한다.

		넷째 줄에는 범위를 출력한다.*/
	cin >> n;
	int temp;
	int max = (-1 * 4001), min = 4001, midIndex = n / 2 + 1, midean = 0, mode = 0;

	for (int i = 1; i <= n; i++)
	{
		cin >> temp;
		//범위
		if (temp > max)
			max = temp;
		if (temp < min)
			min = temp;

		if (temp < 0)
		{
			Mnum[-1 * temp]++;
		}
		else
		{
			num[temp]++;
		}
		sum += temp;
	}
	int pN = 0, mN = 0;
	bool check = false;
	int start = (max > abs(min)) ? max : abs(min);

	for (int i = start; i >= 0; i--)
	{


		if (mode < num[i])
		{

			mode = num[i];
			v.clear();

		}
		if (mode < Mnum[i])
		{


			mode = Mnum[i];

			v.clear();
		}
		if (num[i] == mode)
			v.push_back(i);
		if (Mnum[i] == mode)
			v.push_back(-1 * i);


		pN += num[i];
		mN += Mnum[i];

		if (!check && pN >= midIndex)//중앙값
		{
			midean = i;
			check = true;
		}
		else if (!check && mN >= midIndex)
		{
			midean = (-1 * i);
			check = true;

		}

	}

	
	cout << (int)round(sum / n) << endl;//산술평균
	cout << midean << endl;//중앙값
	sort(v.begin(), v.end());


	if (v.size() > 1)
		cout << v[1] << endl;
	else
		cout << v[0] << endl;//최빈값
	cout << abs(max - min);//범위
}