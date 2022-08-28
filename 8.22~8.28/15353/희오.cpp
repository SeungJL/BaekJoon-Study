#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen("input.txt", "rt", stdin);

	string A;
	string B;
	cin >> A >> B;

	vector<int> res;
	auto it_a = A.end()-1;
	auto it_b = B.end()-1;
	int sum, tmp = 0;

	while (it_a >= A.begin() || it_b >= B.begin()) {
		sum = tmp;
		if (it_a >= A.begin()) sum += *it_a-- - '0';
		if (it_b >= B.begin()) sum += *it_b-- - '0'; 
		res.push_back(sum % 10);
		tmp = sum / 10;
	}
	if (tmp) res.push_back(tmp);

	for (auto it = res.end()-1; it >= res.begin(); it--)
		cout << *it;
	cout << "\n";
	
}