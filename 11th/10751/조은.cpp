#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	char ch;
	long long c=0, co=0, cow=0;
	for(int i=0; i<N; i++) {
		cin >> ch;
		switch(ch) {
			case 'C': c++; break;
			case 'O': co+=c; break;
			case 'W': cow+=co; break;
		}
	}
	cout << cow;
	
	return 0;
}