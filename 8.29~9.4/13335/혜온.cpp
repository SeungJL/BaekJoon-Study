#include <iostream>
#include <algorithm>
#include <queue>



using namespace std;

int truck[1001];

int main() {
	int n, w, L;
	cin >> n >> w >> L;
	for (int i = 0; i < n; i++) {
		cin >> truck[i];
	}
	queue<int> q;
	int ans = 0, sum = 0;
	for (int i = 0; i < n; i++) {
		while (1) {
			if (q.size() == w) {//사이즈가 다 차서 못들어오면
				sum -= q.front();
				q.pop();
			}
			if (sum + truck[i] <= L) break;
			q.push(0);//사이즈가 다 차지 않더라도 다음차가 들어올 타이밍을 계산하기 위해서
			ans++;
		}
		q.push(truck[i]);
		sum += truck[i];
		ans++;
	}
	cout << ans + w << endl;
	return 0;
}
