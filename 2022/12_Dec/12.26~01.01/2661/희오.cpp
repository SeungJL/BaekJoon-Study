#include <iostream>
#include <vector>

using namespace std;

int N;

/* check_same: 좋은 수열인지 확인하는 함수
 *             인접한 두 개의 부분수열 중 동일한 것이 있는지 확인하는 함수
 * parameters - str: 확인하고자 하는 수열
 * return - 좋은 수열이면 true, 아니면 false
 */
bool check_same(string str) {
	vector<char> a;
	vector<char> b;

	for (char ch : str) a.push_back(ch);
	// 뒤에서부터 숫자 하나씩 b로 옮기면서 a의 끝에 b와 동일한 수열이 있는지 확인
	while (a.size() > b.size()) {
		bool isSame = true;
		b.push_back(a.back()); a.pop_back(); 
		auto it_a = a.end()-1;
		for (auto it_b : b) {
			if (*it_a-- != it_b) {
				isSame = false;
				break;
			}
		}
		if (isSame) return true;
	}
	return false;
}

void dfs(int depth, string str) {
	if (depth == N) {
		cout << str << "\n";
		exit(0);
	}

	for (int i=1; i<=3; i++) {
		if (str.back() == i + '0') continue;
		string new_str = str + to_string(i);
		if (!check_same(new_str)) 
			dfs(depth+1, new_str);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen("input.txt", "rt", stdin);

	cin >> N;
	dfs(0, "");
}