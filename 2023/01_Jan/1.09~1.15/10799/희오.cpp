// https://hio9105.tistory.com/entry/BOJ-10799-%EC%87%A0%EB%A7%89%EB%8C%80%EA%B8%B0-datastructures-stack

#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen("input.txt", "rt", stdin);

	char input; 
	vector<int> stack;
	int ans = 0;

	for(int i=0; cin >> input; i++) {
		switch (input) {
			case '(':
				stack.push_back(i); break;
			case ')':
				if (stack.back() == i - 1) // 레이저 -> 스택에 있는 원소 개수만큼 잘린 조각 개수 증가
					ans += (stack.size() - 1); 
				else                       // 쇠막대기 끝 -> 조각 개수 1개 증가
					ans++;
				stack.pop_back();
				break;
		}
	}

	cout << ans << "\n";
	
}