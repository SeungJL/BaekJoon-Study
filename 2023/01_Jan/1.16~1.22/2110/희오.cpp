// https://hio9105.tistory.com/entry/BOJ-2110-%EA%B3%B5%EC%9C%A0%EA%B8%B0-%EC%84%A4%EC%B9%98-binarysearch-parametricsearch

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;
vector<int> houses;
int answer = 0;

/* checker: 공유기 사이 거리기 dist로 했을 때 설치할 수 있는 개수를 구하고
 *          설치해야 하는 개수 조건 C를 충족하는지 확인하는 함수
 * 
 * parameter - dist: 공유기 사이 거리 
 * return - dist를 사이 거리로 공유기를 설치했을 때 설치 가능한 개수가 C 이상이면 true, C 미민이면 false
 */
bool checker(int dist) {
	vector<int>::iterator prev = houses.begin();
	int wifi_cnt = 1; // 설치한 공유기 개수 
	for (auto cur = houses.begin()+1; cur < houses.end(); cur++) {
		if (*cur - *prev < dist) continue; 
		
		// prev 집과 cur 집 사이 거리가 dist 이상일 경우
		wifi_cnt++;
		prev = cur;

		// 공유기 설치 개수 >= C
		if (wifi_cnt >= C) return true; 
	}
	// 공유기 설치 개수 < C
	return false;

}

/* binary_search: 이분 탐색으로 가장 인접한 두 공유기 사이 거리의 최댓값을 구하는 함수
 *
 * parameters - min_dist: 공유기 사이 거리 최솟값
 *            - max_dist: 공유기 사이 거리 최댓값
 * no return
 */
void binary_search(int min_dist, int max_dist) {
	if (min_dist > max_dist) return; // wrong range

	int mid = (min_dist + max_dist) / 2;

	// mid가 공유기 사이 거리일 때, C개 설치를 할 수 없으므로 거리를 더 줄여야 됨
	if (!checker(mid)) 
		binary_search(min_dist, mid-1);
		
	// mid가 공유기 사이 거리일 때, C개 이상 설치할 수 있으므로 거리를 더 늘려야 됨 
	else {
		answer = max(answer, mid);
		binary_search(mid+1, max_dist);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen("input.txt", "rt", stdin);

	cin >> N >> C;
	for (int i=0; i<N; i++) {
		houses.push_back(0);
		cin >> houses[i];
	}

	sort(houses.begin(), houses.end());

	binary_search(1, houses[N-1] - houses[0]);

	cout << answer << "\n";
}