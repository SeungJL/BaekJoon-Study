#include <stack>
#include <iostream>
#include <algorithm>
#include <queue>;

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	stack <int> s1; // 임시로 담을 스택
	bool visit[100001] = { 0 }; // S1 스택에 해당 숫자가 존재하는지 판단
	int ans[100001]; // 최종 정답이 되어야 하는 순열
	int firstArr[100001]; // 처음 오름차순으로 입력할 순열 순서
	queue <char> speak; // 최종적으로 출력 push/pop 순서

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> M;
		ans[i] = M;
		firstArr[i] = M;
	}
	sort(firstArr, firstArr + N);
	int i = 0;
	int j = 0;
	while (1) {
		if (s1.empty() == 0 && s1.top() == ans[j]) { // pop했는데 또 정답이 나오는 경우
			speak.push('-');
			int temp = ans[j];
			s1.pop();
			visit[temp] = 0;
			j++;
			continue;
		}
		if (i == N) {
			break;
		}
		int selectNum = firstArr[i];
		if (visit[selectNum] == 1) {
			cout << "NO";
			return 0;
		}
		s1.push(selectNum);
		speak.push('+');
		visit[selectNum] = 1;
		if (selectNum == ans[j]) {
			s1.pop();
			speak.push('-');
			visit[selectNum] = 0;
			j++; // ans 순열 한칸 증가. 다음 거 찾으면 됨.

		}


		i++; // firstArr index 한칸 증가 다음거 입력.

	}
	if (s1.empty() == 0) { cout << "NO"; }
	else {
		while (!speak.empty()) {
			cout << speak.front() << '\n';
			speak.pop();
		}
	}
}