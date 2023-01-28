// https://hio9105.tistory.com/entry/BOJ-11053-%EA%B0%80%EC%9E%A5-%EA%B8%B4-%EC%A6%9D%EA%B0%80%ED%95%98%EB%8A%94-%EB%B6%80%EB%B6%84-%EC%88%98%EC%97%B4-dp-binarysearch

#include <iostream>
#include <vector>

using namespace std;

/* lower_bound: 주어진 vector에서 x보다 크거나 같은 값의 위치를 구하는 함수 */
vector<int>::iterator lower_bound(vector<int> &LIS, int x) {
	for (auto it=LIS.begin(); it < LIS.end(); it++) {
		if (*it >= x) return it;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "rt", stdin);

	int N, input;
	vector<int> LIS;
	LIS.push_back(0); // back()으로 빈 벡터 배열 접근 방지를 위함

	cin >> N;
	for (int i=1; i<=N; i++) {
		cin >> input;
		if (input > LIS.back()) 
			LIS.push_back(input);
		else 
			*(lower_bound(LIS, input)) = input;
	}

	cout << LIS.size()-1 << "\n";
}