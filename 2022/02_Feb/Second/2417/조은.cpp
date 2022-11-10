#include <iostream>
#include <cmath>
using namespace std;

int main() {
	unsigned long long N;
	cin >> N;
	
	unsigned long long sq = sqrt(N);
	if(sq*sq < N) {
		cout << ++sq;
	}
	else {
		cout << sq;
	}

	return 0;
}