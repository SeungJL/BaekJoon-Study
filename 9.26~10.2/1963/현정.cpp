#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int a, b;
queue<int> q;
int timearr[10001];
bool primearr[10001];

void SetPrime() {
	for (int j = 1000; j < 10000; j++) {
		for (int i = 2; i < j / 2; i++) {
			if (j%i == 0) {
				primearr[j] = false;
				break;
			}
		}
	}
	return;
}

int changeAtPosition(int a, int b, int position) {
	int ret = 0;	
	//cout << a << " -> " << b << ", "<<position<<" 위치 변환 ";
	int num[4];
	for (int i = 3; i >=0; i--) {
		num[i] = a % 10;
		a /= 10;
	}
	for (int i=1; i <=4; i++) {
		if (i == position)	ret += b;
		else ret += num[i-1];
		ret *= 10;
	}
	//cout << ret/10 << " 완료\n";

	return ret/10;
}

void BFS(int num) {
	q.push(num);
	timearr[num] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		//cout << now <<" ("<<timearr[num]<<") : ";
		if (now == b) {
			cout << timearr[b]-1 << "\n";
			return;
		}

		for (int i = 1; i <=4; i++) {
			for (int j = 0; j < 10; j++) {
				if (i == 1 && j == 0)	continue;
				
				int next = changeAtPosition(now, j, i);
				if (primearr[next] && timearr[next] == 0) {
					q.push(next);
					timearr[next] = timearr[now] + 1;
					//cout << next << " ";
				}
			}
		}
		//cout << "\n";
	}
	cout << "Impossible\n";
}

void init() {
	while (!q.empty()) {
		q.pop();
	}
	memset(timearr, 0, sizeof(timearr));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	memset(primearr, true, sizeof(primearr));
	SetPrime();

	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		init();
		BFS(a);
	}
	return 0;
}
