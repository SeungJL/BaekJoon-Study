#include<iostream>
#include<string>

using namespace std;

int N, cnt;
bool num[1000];
string q, temp;
int strike, ball;
int strikeTmp, ballTmp;
int main()
{

	cin >> N;


	while (N--)
	{

		cin >> q >> strike >> ball;//1 1
		for (int i = 123; i < 998; i++)
		{
			temp = to_string(i);
			strikeTmp = 0, ballTmp = 0;
			//0이 들어간 것도 제외
			if (temp[0] == temp[1] || temp[0] == temp[2] || temp[1] == temp[2] || (temp[1] - '0') * (temp[2] - '0') == 0)
			{
				num[i] = true;

				continue;
			}
			for (int j = 0; j < 3; j++)
				for (int k = 0; k < 3; k++)
				{
					if (j == k)
					{
						if (q[j] == temp[k])
							strikeTmp++;

					}
					else
					{
						if (q[j] == temp[k])
							ballTmp++;
					}

				}

			if (strike != strikeTmp || ball != ballTmp)
				num[i] = true;


		}

	}

	int ans = 0;
	for (int i = 123; i < 998; i++)
	{
		if (!num[i])
			ans++;
	}
	cout << ans << "\n";
}