#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	unordered_map<string, int> u_map;
	vector<string> vec;

	int max = 0;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		if (u_map.find(str) != u_map.end()) {		//이미 입력받은 적 있는 문자열이면,
			u_map[str]++;
		}
		else {
			u_map[str] = 1;
		}

		if (u_map[str] > max) {		//최고치 갱신이면,
			max = u_map[str];
			while (!vec.empty()) vec.pop_back();
			vec.push_back(str);
		}
		else if (u_map[str] == max) {		//최고치와 같으면,
			vec.push_back(str);
		}
	}

	sort(vec.begin(), vec.end());
	cout << vec[0] << endl;

	return 0;
}