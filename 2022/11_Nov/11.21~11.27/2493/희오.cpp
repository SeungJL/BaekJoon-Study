// https://hio9105.tistory.com/entry/BOJ-2493-%ED%83%91-datastructures-stack

#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen("input.txt", "rt", stdin);

	/* input */
	int N, input;
	cin >> N;

	vector<int> height(N+1);	// 탑의 높이 정보
	vector<int> stack;		// 아직 수신탑을 찾지 않은 탑의 인덱스
	vector<int> ans(N+1, 0);
	for (int i=1; i<=N; i++)
		cin >> height[i];

	/* solve */
	for (auto i = N; i >= 1; i--) { // 오른쪽부터 왼쪽으로 순회, 역순
		while (!stack.empty()) {
			int top = stack.back();
			if (height[i] < height[top]) 
				break; 	// i(왼)가 top(오)보다 낮은 경우, i는 top의 신호를 받을 수 없음
			ans[top] = i;
			stack.pop_back();
		}
		stack.push_back(i);
	}

	/* print answer */
	for (int i=1; i<=N; i++)
		cout << ans[i] << " ";
	
}