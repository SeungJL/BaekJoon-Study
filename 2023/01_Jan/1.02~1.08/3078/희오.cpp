// https://hio9105.tistory.com/entry/BOJ-3078-%EC%A2%8B%EC%9D%80-%EC%B9%9C%EA%B5%AC-datastructures-queue-slidingwindow

#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen("input.txt", "rt", stdin);

	int N, K;
	string name;
	vector<int> list[21];	// 이름 길이에 따라 나눈 학생 리스트, list[i] = 이름의 길이가 i인 학생들의 등수

	/* input & init */
	cin >> N >> K;
	for (int i=1; i<=N; i++) {
		cin >> name;
		list[name.length()].push_back(i); // 주어진 이름의 길이에 해당하는 배열에 현재 등수 추가 
	}

	/* solve */
	long long ans = 0;
	for (int i=2; i<=20; i++) {
		if (list[i].size()) {
			vector<long long> sum(list[i].back()+1, 0); // 누적합 배열
			for (auto e : list[i]) sum[e] = 1;			// 현재 리스트에 포함되어 있는 등수를 1로 체크
			for (int j=1; j<=list[i].back(); j++) {
				// 현재 리스트에 포함된 등수일 경우
				// j-k ~ j-1 사이에 있는 학생의 수 = 현재 등수의 학생과 좋은 친구가 되는 학생의 수
				if (sum[j]) 
					ans += (j > K) ? sum[j-1] - sum[j-K-1] : sum[j-1]; 
				sum[j] += sum[j-1];
			}
		}
	}

	cout << ans << "\n";
}