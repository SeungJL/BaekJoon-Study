#include <iostream>

using namespace std;

int a[128][128];
int wCnt = 0, bCnt = 0;	//하얀색 색종이의 개수, 파란색 색종이의 개수

void p(int c, int r, int n)
{
	bool flag = true;

	int initColor = a[c][r];	//왼쪽 위 칸의 색종이 색깔
	for (int i = c; i < c + n; i++) {
		for (int j = r; j < r + n; j++) {
			if (initColor != a[i][j]) {
				flag = false;
				break;
			}
		}
		if (!flag) break;
	}

	if (flag) {	//잘라진 종이가 모두 같은 색인 경우
		if (initColor == 0) wCnt++;	//잘라진 종이가 모두 흰색이라면 하얀색 색종이의 개수 1 증가
		else bCnt++;	//잘라진 종이가 모두 파란색이라면 파란색 색종이의 개수 1증가
	}
	else {	//잘라진 종이에 다른 색이 존재하는 경우 분할정복
		p(c, r, n / 2); //왼쪽 위
		p(c + n / 2, r, n / 2);	//오른쪽 위
		p(c, r + n / 2, n / 2);	//왼쪽 아래
		p(c + n / 2, r + n / 2, n / 2);	//오른쪽 아래
	}
}

int main(void)
{
	int N;	//전체 종이의 한 변의 길이
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
		}
	}
	
	p(0, 0, N);
	cout << wCnt << '\n' << bCnt;

	return 0;
}