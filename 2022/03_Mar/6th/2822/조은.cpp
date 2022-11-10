#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> v(8);
	map<int,int> m;
	for(int i=0; i<8; i++) {
		cin >> v[i];
		m.emplace(v[i], i+1);
	}
	
	sort(v.begin(), v.end(), greater<int>());
	int total=0;
	int a[5] = { 0 };
	for(int i=0; i<5; i++) {
		total+=v[i];
		a[i] = m[v[i]];
	}
	sort(a, a+5);
	cout << total << '\n';
	for(int i=0; i<5; i++) {
		cout << a[i] << ' ';
	}

	return 0;
}