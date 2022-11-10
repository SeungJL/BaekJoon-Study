#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
	int cases;
	cin >> cases;

	for (int i = 0; i < cases; i++) {
		int n;
		cin >> n;
		unordered_map<string, int> map;
		for (int j = 0; j < n; j++) {
			string s1, s2;
			cin >> s1 >> s2;
			if (map.find(s2) == map.end()) {		//들어온 적 없으면
				map[s2] = 1;
			}
			else {
				map[s2]++;
			}
		}

		//곱의 법칙(단 0개인것도 포함하기 때문에 1을 더해서 곱한다. 그대신 전부다 0개인 케이스를 제외해야 하기에 최종적으로 1을 빼야함)
		int mul = 1;
		for (auto p : map) {
			mul *= (p.second + 1);
		}
		cout << mul - 1 << endl;
	}

	return 0;
}