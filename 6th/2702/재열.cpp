#include <iostream>

using namespace std;

int getLCM(int a, int b, int A, int B) {		//최소공배수
	if (a % b == 0) return a;
	if (b % a == 0) return b;

	if (a > b) 
		return getLCM(a, b + B, A, B);
	else	
		return getLCM(a + A, b, A, B);
}

int getGCD(int a, int b) {		//최대공약수
	if (a % b == 0) return b;
	if (b % a == 0) return a;
	
	if (a > b) 
		return getGCD(a % b, b);
	else 
		return getGCD(a, b % a);
}

int main() {
	int T;
	cin >> T;
	
	for (int i = 0; i < T; i++) {
		int a, b;
		cin >> a >> b;

		cout << getLCM(a, b, a, b) << ' ' << getGCD(a, b) << endl;
	}

	return 0;
}