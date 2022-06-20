#include <iostream>
#include <algorithm>

using namespace std;

int p[1001];

int main(void)
{
	int N, L, cnt = 1;
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		cin >> p[i];
	}

	sort(p, p + N); // 물이 새는 곳의 위치 오름차순으로 정렬
	
	int tmp = p[0]; // 물이 처음 새는 곳

	for (int i = 1; i < N; i++) {
		if (tmp + L < p[i] + 1) {	//테이프로 물을 막을 수 있는 구간을 벗어나면 테이프의 수 추가
			cnt++;
			tmp = p[i];	// 물이 새는 곳을 다시 조정
		}
	}

	cout << cnt;

	return 0;
}