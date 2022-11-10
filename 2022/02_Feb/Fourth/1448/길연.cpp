// 백준 1448번 

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int maxTriangle(vector<int> triangle) {
	// 세 변길이의 합의 최댓값이니 내림차순 정렬 필요
	// a < b < 일때, c < a+b 면 삼각형 성립
	
	sort(triangle.begin(), triangle.end(), greater<int>()); // 내림차순

	for (int i = 0; i < triangle.size() - 2; i++) {
		if (triangle[i] < triangle[i + 1] + triangle[i + 2])
			return triangle[i] + triangle[i + 1] + triangle[i + 2];
	}

	return -1; // 삼각형 만들어지지않는 경우
}

int main() {

	int num;
	cin >> num;

	vector<int> triangle;
	while (num--) {
		int straw;
		cin >> straw;
		triangle.push_back(straw);
	}
	
	cout << maxTriangle(triangle) << endl;

	return 0;
}

