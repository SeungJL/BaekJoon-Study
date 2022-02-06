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

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		if (u_map.find(str) != u_map.end()) {		//이미 입력받은 적 있는 문자열이면,
			u_map[str]++;
		}
		else {
			u_map[str] = 1;
		}
	}

	//가장 많이 등장한 문자열 파악
	int max = 0;
	string maxStr;
	bool isRepeated = false;
	for (auto x : u_map) {
		if (x.second > max) {		//등장횟수가 최고치 갱신이면,
			max = x.second;
			maxStr = x.first;
			//배열 비우고 지금 문자열 삽입
			while (!vec.empty()) vec.pop_back();
			vec.push_back(x.first);
			isRepeated = false;		
		}
		if (x.second == max) {		//등장횟수와 기존 최고치와 같으면
			vec.push_back(x.first);		//배열에 추가
			isRepeated = true;		//중복신호 true로
		}
	}

	if (isRepeated) 
		sort(vec.begin(), vec.end());
	cout << vec[0] << endl;

	return 0;
}


