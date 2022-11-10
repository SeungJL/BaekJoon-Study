#include<iostream>
#include<cmath>

using namespace std;

int N;
int X1, Y1, r1, x2, y2, r2, cnt;
int d;

int main()
{

	cin >> N;
	while (N--)
	{
		cin >> X1 >> Y1 >> r1 >> x2 >> y2 >> r2;

		//조규현과 백승환의 좌표가 같다면
		if (X1 == x2 && Y1 == y2 && r1 == r2)
		{
			if (r1 == 0)
				cout << "1" << endl;
			else
				cout << "-1" << endl;
			continue;
		}
		//조규현과 백승환의 거리 =d
		d = (X1 - x2) * (X1 - x2) + (Y1 - y2) * (Y1 - y2);


		//외접과 내접
		if (d == (r1 + r2) * (r1 + r2) || (r1 - r2) * (r1 - r2) == d)
			cnt = 1;
		//한 원이 다른 원을 포함 or 멀리 떨어져있을때
		else if (d > (r1 + r2) * (r1 + r2) || ((r1 - r2) * (r1 - r2) > d))//||(d<r1*r1&&d<r2*r2))
			cnt = 0;
		else if (r1 - d > r2 && r2 - d > r1)
			cnt = 0;
		else
			cnt = 2;

		cout << cnt << endl;

	}
}