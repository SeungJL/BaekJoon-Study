/*
https://www.acmicpc.net/problem/15665
백준 2096 : 내려가기
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> input(3);
	vector<int> min_vector(3);
	vector<int> max_vector(3);

	for (int i = 0; i < n; i++) {
		cin >> input[0] >> input[1] >> input[2];

		//최솟값 먼저 계산
		vector<int> tem = min_vector; //tem 벡터에 지금까지의 값 넣어주기

		min_vector[0] = input[0] + min(tem[0], tem[1]);
		min_vector[1] = input[1] + min(min(tem[0], tem[1]), tem[2]);
		min_vector[2] = input[2] + min(tem[1], tem[2]);

		// 맥스값 먼저 계산
		tem = max_vector;

		max_vector[0] = input[0] + max(tem[0], tem[1]);
		max_vector[1] = input[1] + max(max(tem[0], tem[1]), tem[2]);
		max_vector[2] = input[2] + max(tem[1], tem[2]);
	}

	//0,1,2 값들 중 최댓값, 최솟값을 출력하기
	// max, min 함수는 파라미터를 2개만 받으므로 2중첩으로 작성
	cout << max(max(max_vector[0], max_vector[1]), max_vector[2]) << " ";
	cout << min(min(min_vector[0], min_vector[1]), min_vector[2]) << "\n";

	return 0;
}
