/*
https://www.acmicpc.net/problem/15663
백준 15663 : N과 M(9)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

int N, M; //N,M 
map<vector<int>, bool> dic; // 중복되는 수열 제거하기 위함. <path, 방문여부> pair 값 전달

// num 배열 안의 숫자를 뽑을 것
// 지금까지의 경로를 path, 중복되는 값을 제거하기 위해 지금까지 방분한 isvistied 배열을 사용
void BackTracking(vector<int> num, vector<int> path,bool isvisited[]) {
	if (path.size() == M) {
		if (dic[path] == false) { //중복되지 않으면 출력
			for (int i = 0; i < path.size(); i++) {
				cout << path[i] << " ";
			}
			cout << "\n";
			dic[path] = true;
		}
		return;
	}
	//cout << count << "\n";
	for (int i = 0; i < N; i++) {
		if (!isvisited[i]) {
			vector<int> newPath = path;
			newPath.push_back(num[i]); // 숫자 i를 추가함
			isvisited[i] = true;
			BackTracking(num, newPath, isvisited);
			isvisited[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	vector<int> path;
	vector<int> number(N);
	for (int i = 0; i < N; i++) {
		cin >> number[i]; //입력값 넣기
	}
	sort(number.begin(), number.end()); //사전 순으로 넣어야 하므로 정렬

	bool isvisited[10];
	for (int i = 0; i <= N; i++) {
		isvisited[i] = false; //isvisited 함수 초기화
	}
	BackTracking(number, path, isvisited);
	return 0;
}
