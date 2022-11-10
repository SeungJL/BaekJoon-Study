#include <iostream>
#include <stack>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

int arr[100001] = { 0, };
int cnt = 0;

int main(void)
{
	int n;
	cin >> n;

	vector<int> v;
	vector<char> ans;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		v.push_back(i);
		ans.push_back('+');

		while (!v.empty() && v.back() == arr[cnt]) {
			v.pop_back();
			ans.push_back('-');
			cnt++;
		}
	}

	if (!v.empty()) cout << "NO";
	else
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << '\n';
	return 0;
}