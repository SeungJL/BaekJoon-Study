#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	unordered_set<int> uset;

	//집합A
	for (int i = 0; i < a; i++) {
		int input;
		cin >> input;
		uset.insert(input);
	}

	//집합B
	for (int i = 0; i < b; i++) {
		int input;
		cin >> input;
		if (uset.find(input) != uset.end()) {		//만약 이미 존재하면
			uset.extract(input);
		}
		else {
			uset.insert(input);
		}
	}

	cout << uset.size() << endl;

	return 0;
}