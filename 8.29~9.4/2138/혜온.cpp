#include<iostream>
#include<string>

using namespace std;

//1080
//2 3 3 3 3 2 와 같이 가장 적은 방법의 수가 1개가 아니기 때문에 행렬 문제의 방법으로는 해결할 수 없다.
//하지만 a[0] 전구의 상태를 먼저 결정하면, 각각의 칸을 바꿀 수 있는 방법을 하나로 만들 수 있다.
//1 2 3 3 3 2 와 같이 볼 수 있고, 이제 a[0]과 b[0]의 상태를 비교하여 다르다면 a[1]의 버튼을 눌러서 상태를 맞출 수 있다
int main()
{
	int n, cnt = 0, cnt2 = 1;
	string bulb, copyBulb, copyBulb2;
	cin >> n;
	cin >> bulb >> copyBulb;
	copyBulb2 = copyBulb;
	//1-copyBulb2[1];
	//copyBulb2[1] += 1;
	//cout << '1' - copyBulb2[1];
	copyBulb2[0] = '1' - copyBulb2[0] + '0';
	copyBulb2[1] = '1' - copyBulb2[1] + '0';
	//cout << copyBulb << "  b   " << copyBulb2<< endl;

	if (bulb == copyBulb)
	{
		cout << 0 << endl;
		return 0;
	}
	//0번째 스위치를 누르지 않은 경우
	for (int i = 1; i < n; i++)
	{
		if (bulb[i - 1] != copyBulb[i - 1])
		{
			copyBulb[i - 1] = '1' - copyBulb[i - 1] + '0';
			copyBulb[i] = '1' - copyBulb[i] + '0';
			copyBulb[i + 1] = '1' - copyBulb[i + 1] + '0';
			cnt++;

		}
		if (bulb[i - 1] != copyBulb2[i - 1])
		{
			copyBulb2[i - 1] = '1' - copyBulb2[i - 1] + '0';
			copyBulb2[i] = '1' - copyBulb2[i] + '0';
			copyBulb2[i + 1] = '1' - copyBulb2[i + 1] + '0';
			cnt2++;

		}
	}
	//cout << copyBulb << " v" << copyBulb2 << endl;
	if (bulb != copyBulb && bulb != copyBulb2)
	{
		cout << -1 << endl;
		return 0;
	}
	else if (bulb == copyBulb && bulb != copyBulb2)
	{
		cout << cnt;
	}
	else if (bulb != copyBulb && bulb == copyBulb2)
	{
		cout << cnt2;
	}
	else
	{
		if (cnt > cnt2)
			cout << cnt2;
		else
			cout << cnt;
	}

}
