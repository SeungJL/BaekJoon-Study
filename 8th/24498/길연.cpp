// 백준 24498번 blobnom

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;



int main() {

	int n;
	cin >> n;

	vector<int> v;
	int tmax = 0;


	int ans;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	for (int i = 1; i < n - 1; i++) {	

		int step;
		step = v[i] + min(v[i - 1], v[i + 1]);

		if (tmax < step)
			tmax = step;

	}
	
	ans = max({ v.front(), v.back(), tmax });

	cout << ans << endl;

	return 0;
}


