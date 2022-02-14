#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main() {
	int n;
	cin >> n;

	vector<int> nums;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		nums.push_back(a);
	}

	sort(nums.begin(), nums.end(), compare);		//내림차순 정렬 (큰 수가 앞으로)

	//가장 큰 세 숫자부터 탐색.
	//삼각형이 성립되면 길이 출력하고 프로그램 종료
	for (int i = 0; i <= n-3; i++) {
		for (int j = i+1; j <= n-2; j++) {
			for (int k = j+1; k <= n-1; k++) {
				if (nums[i] < nums[j] + nums[k]) {
					cout << nums[i] + nums[j] + nums[k] << endl;
					return 0;
				}
				else break;		//i,j가 고정일때 k가 최대일때도 삼각형이 성립이 안되면 더이상 해볼 필요 없음. (다음으로 넘어감)
			}
		}
	}

	cout << -1 << endl;

	return 0;
}