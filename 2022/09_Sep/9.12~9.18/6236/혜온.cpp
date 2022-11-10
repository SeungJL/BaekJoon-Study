#include<iostream>

using namespace std;
int N, M, K, sum; //N일동안 M 번만
int num[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
		sum += num[i];
	}

	int left = 1, right = sum, mid, cnt, ans = sum;//왜 left가 0으로 시작되면 안될까?
	bool chk = false;

	while (left <= right)
	{

		mid = (left + right) / 2;
		K = mid;
		cnt = 1;
		for (int i = 0; i < N; i++)
		{
			if (num[i] > mid)
			{
				chk = true;
				break;
			}
			if (K >= num[i])
			{
				K -= num[i];

			}
			else//모자라게 되면 남은 금액은 통장에 집어넣고 다시 K원을 인출한다. 
			{
				K = mid;
				cnt++;
				K -= num[i];

			}

		}
		//	cout<<right<<"  "<<left<<"  " << mid << endl;
		if (cnt > M || chk)
		{
			left = mid + 1;
			chk = false;
		}
		else if (cnt <= M)
		{
			ans = mid;
			right = mid - 1;
		}

	}

	cout << ans;
}