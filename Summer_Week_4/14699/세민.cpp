#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int N, M, x, y, max_h;
int arr[5001];
int cache[5001];
vector<int> node[5001];

int path(int i, int h) {
	if (h == max_h || node[i].empty()) return 1;
	int & ret = cache[i];
	if (ret != -1) return ret;

	ret = 1;
	for (auto& ptr : node[i]) {
		if (h < arr[ptr]) {
			ret = max(ret, path(ptr, arr[ptr]) + 1);
		}
	}

	return ret;
}

void cal() {
	memset(cache, -1, sizeof(cache));
	for (int i = 1; i <= N; i++) {
		cout << path(i, arr[i]) << '\n';
	}
}

int main(void)
{
	cin >> N >>		M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		max_h = max(max_h, arr[i]);
	}
	for (int j = 1; j <= M; j++) {
		cin >> x >> y;
		node[x].push_back(y);
		node[y].push_back(x);
	}
	cal();

	return 0;
}