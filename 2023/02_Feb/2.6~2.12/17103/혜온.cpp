#include<iostream>

using namespace std;

int T, tmp, half, ans;
bool num[1000001];

int main()
{


	for (int i = 2; i * i <= 1000000; i++) {
		if (num[i]) continue;
		for (int j = i + i; j <= 1000000; j += i)
			num[j] = true;
	}
	cin >> T;
	while (T--)
	{
		cin >> tmp;
		half = tmp / 2;
		ans = 0;
		for (int i = 2; i <= half; i++)
			if (!num[i] && !num[tmp - i])
				ans++;
		cout << ans << endl;
	}
}