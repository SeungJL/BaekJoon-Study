#include <iostream>

using namespace std;

int main() {
	long long a, b;
	cin >> a >> b;

	int Lcount = 0;
	int Rcount = 0;

	//둘다 1이 될 때 까지 반복
	while (a != 1 || b != 1) {
		//어느 한 쪽이 1이 되면 한번에 구할 수 있다!
		if (a == 1) {		
			Rcount += (b-1);
			break;
		}
		else if (b == 1) {
			Lcount += (a-1);
			break;
		}

		if (a > b) {
			Lcount++;
			a = a - b;
		}
		else {
			Rcount++;
			b = b - a;
		}
	}

	cout << Lcount << ' ' << Rcount << endl;

	return 0;
}
