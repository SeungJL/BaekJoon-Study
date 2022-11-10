#include <iostream>
#include <vector>
#include <algorithm> // sort
#include <cmath> // round

using namespace std;

#define INF_VALUE 5000

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen("input.txt", "rt", stdin);

	int N, input;
	double sum = 0;
	int cnt[8001] = {}, max_cnt = 0;

	cin >> N;
	for(int i=0; i<N; i++) {
		cin >> input;
		sum += input;
		cnt[input + 4000]++;
		if (cnt[input + 4000] > max_cnt) max_cnt = cnt[input + 4000];
	}

    /* solve */
	// 산술평균 mean
	double mean = round(sum / N);
    
	int median = INF_VALUE, cnt_sum = 0;
	vector<int> mode;
    int max_num = INF_VALUE, min_num = INF_VALUE;
	for (int i=-4000; i<=4000; i++) {
		if (cnt[i+4000]) {
			// 중앙값 median
			cnt_sum += cnt[i+4000];
			if (median == INF_VALUE && cnt_sum > N/2) {
				median = i;
			}

			// 최빈값 mode
			if (cnt[i+4000] == max_cnt) mode.push_back(i);

			// 범위 range
			max_num = i;
			if (min_num == INF_VALUE) min_num = i;
		}
	}

    /* print */
	// 산술평균 mean
	(mean == 0) ? cout << "0\n" : cout << mean << "\n";
	// 중앙값 median
	cout << median << "\n";
	// 최빈값 mode
	(mode.size() == 1) ? cout << mode[0] << "\n" : cout << mode[1] << "\n";
	// 범위 range
	cout << max_num - min_num << "\n";

}