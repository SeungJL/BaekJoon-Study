#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int main() {
	int N;
	cin >> N;
	string str;
	vector<int> vec;
	stack<double> nums;

	cin >> str;
	for (auto c : str) {
		vec.push_back(100 + c);
	}

	for (int i = 0; i < N; i++) {
		int inputNum;
		cin >> inputNum;
		for (int j = 0; j < vec.size(); j++) {	
			if (vec[j] == (100 + 'A' + i))	
				vec[j] = inputNum;
		}
	}

	for (auto n : vec) {
		if (n >= 0 && n <= 100) {		
			nums.push(n);
		}
		else if (n == (100 + '+')) {
			double n1 = nums.top();
			nums.pop();
			double n2 = nums.top();
			nums.pop();
			nums.push(n1 + n2);
		}
		else if (n == (100 + '-')) {
			double n1 = nums.top();
			nums.pop();
			double n2 = nums.top();
			nums.pop();
			nums.push(n2 - n1);
		}
		else if (n == (100 + '*')) {
			double n1 = nums.top();
			nums.pop();
			double n2 = nums.top();
			nums.pop();
			nums.push(n1 * n2);
		}
		else if (n == (100 + '/')) {
			double n1 = nums.top();
			nums.pop();
			double n2 = nums.top();
			nums.pop();
			nums.push(n2 / n1);
		}
	}
	double result = nums.top();
	printf("%.2lf\n", result);

	return 0;
}
