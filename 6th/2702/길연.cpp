// 백준2702번 초6 수학

#include <iostream>


using namespace std;

int GCD(int a, int b) { // 최대공약수
	int n;
	while (b !=0 ) {
		n = a % b;
		a = b;
		b = n;
	}
	return a;
}

int LCM(int a, int b) {
	
	return (a * b) / GCD(a, b);
}


int main() {

	int T;
	cin >> T;

	while (T--) {
		int a, b;
		cin >> a >> b; 
		cout << LCM(a,b) <<" "<< GCD(a, b) <<  endl;
	}


	return 0;
}
