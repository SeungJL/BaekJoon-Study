#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> nums(n+1);
	set<int> results;

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	vector<int> orders;
	for (int i = 0; i < n; i++) 
		orders.push_back(i);

	do {
		int temp = 0;
		for (int i = 0; i < k; i++) {
			if (nums[orders[i]] < 10) {		//일의 자리이면
				temp = (temp*10 + nums[orders[i]]);
			}
			else {		//십의 자리이면
				temp = (temp*100 + nums[orders[i]]);
			}
		}
		results.insert(temp);
	} while (next_permutation(orders.begin(), orders.end()));

	cout << results.size() << endl;

	return 0;
}