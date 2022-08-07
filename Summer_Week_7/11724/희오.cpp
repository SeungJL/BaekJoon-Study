// BOJ 11724

#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen("input.txt", "rt", stdin);

	int N, M;
	cin >> N >> M;

 	vector<int> arr(N+1, 0);

	int v1, v2, set_cnt = 0, res = 0;
	for(int i = 0; i < M; i++) {
		cin >> v1 >> v2;

		if (arr[v1] != 0 && arr[v2] != 0) {
			if (arr[v1] != arr[v2]) {
				res--;
				int tmp = arr[v2];
				for(auto it=arr.begin(); it<arr.end(); it++) {
					if (*it == tmp) *it = arr[v1];
				}
			}
		}
		else if (arr[v1] == 0 && arr[v2] == 0) {
			set_cnt++;
			res++;
			arr[v1] = set_cnt;
			arr[v2] = set_cnt;
		}
		else if (arr[v1] != 0 && arr[v2] == 0) arr[v2] = arr[v1];
		else if (arr[v1] == 0 && arr[v2] != 0) arr[v1] = arr[v2];
		
	}

	for (auto it = arr.begin()+1; it < arr.end(); it++)
		if (*it == 0) res++;

	cout << res << "\n";

} 