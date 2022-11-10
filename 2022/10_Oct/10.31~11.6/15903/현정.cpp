#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector < long long > arr(n); //각 변수가 1,000,000 값에 총 1000개를 가지므로 int 범위로는 부족하다
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < m; i++) {
		sort(arr.begin(), arr.end()); //매번 정렬하여 0,1번째 배열의 값에 합으로 덮어쓰기 한다
		long long sum = arr[0] + arr[1];
		arr[0] = sum;
		arr[1] = sum;
	}

	long long sum = 0;
	for (int i = 0; i < n; i++) { //총합을 구하고 출력한다
		sum += arr[i];
	}
	cout << sum << "\n";
	return 0;
}
