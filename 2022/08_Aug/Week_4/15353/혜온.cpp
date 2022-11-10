#include <iostream>
#include <vector>
#include<string>
using namespace std;

int num1[10001] = { 0, }, num2[10001] = { 0, };
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string a = "", b = "", temp = "";
	int c = 0;
	cin >> a >> b;

	if (a.size() < b.size()) {
		temp = a;
		a = b;
		b = temp;
	}
	for (int i = 0; i < a.size(); i++) num1[i] = a[i] - '0';
	for (int i = 0; i < b.size(); i++) num2[i] = b[i] - '0';
	int aS = a.length(), bS = b.length();
	int p = 0;
	int sum;
	while (aS > 0 || p)
	{

		sum = num1[--aS] + num2[--bS] + p;

		v.push_back(sum % 10);
		if (sum > 9)
			p = 1;
		else
			p = 0;

	}
	for (int i = v.size() - 1; i >= 0; i--) cout << v[i];
	return 0;
}
