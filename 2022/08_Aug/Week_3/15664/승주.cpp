#include <iostream>
#include <string>
#include <vector>>
#include <algorithm>
#include <map>
#include <set>
using namespace std;


int firstArr[10]; // 처음 배열
int N, M;
int arr[10] = {}; // 탐색 배열

set <vector<int>>S;

void Permutation(int depth, int index) {

	if (index == M) {
		vector<int> V;
		for (int i = 0; i < M; i++) {
			V.push_back(arr[i]);
		}
		S.insert(V);
	}
	if (depth >= N || index >= M) { return; }

	Permutation(depth + 1, index);
	arr[index] = firstArr[depth];
	Permutation(depth + 1, index + 1);
	arr[index] = 0;
}


int main() {
	int X;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> firstArr[i];
	}
	sort(firstArr, firstArr + N);

	Permutation(0, 0);

	for (auto Vpos : S) {
		for (auto elem : Vpos) {
			cout << elem << " ";
		}
		cout << endl;
	}

}