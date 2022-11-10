#include <iostream>
#include <queue>
#include <cstring>
#include<string>
#include <utility>


using namespace std;

int visit[10001] = {};

void BFS(int A, int B, string s) {
	queue <pair<int, string>> q;
	int T1, T2, T3;
	q.push(make_pair(A, s));
	while (!q.empty()) {
		int front = q.front().first;
		string str = q.front().second;
		if (front == B) { cout << str; break; }
		q.pop();
		T1 = front * 2 % 10000;
		if (visit[T1] == 0) {
			visit[T1] = 1;
			q.push(make_pair(T1, str + 'D'));
		}
		if (front == 0 && visit[9999] == 0) {
			visit[9999] = 1;
			q.push(make_pair(9999, str + 'S'));
		}
		else if (front != 0 && visit[front - 1] == 0) {
			visit[front - 1] = 1;
			q.push(make_pair(front - 1, str + 'S'));
		}
		int k = front / 1000;
		T2 = (front % 1000) * 10;
		if (visit[T2 + k] == 0) {
			visit[T2 + k] = 1;
			q.push(make_pair(T2 + k, str + 'L'));
		}
		k = front % 10;
		T3 = front / 10 + 1000 * k;
		if (visit[T3] == 0) {
			visit[T3] = 1;
			q.push(make_pair(T3, str + 'R'));
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, A, B;
	string s;
	cin >> T;
	for (int i = 0; i < T; i++) {
		s = "";
		cin >> A >> B;
		visit[A] = 1;
		BFS(A, B, s);
		memset(visit, 0, 10001);
		cout << '\n';
	}
}