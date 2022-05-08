#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int gcd(int n, int m) {
	int r = n%m;
	if(r==0) return m;
	return gcd(m, r);
}

int main() {
	int n, m;
	scanf("%d:%d", &n, &m);

	int g = gcd(n,m);
	printf("%d:%d", n/g, m/g);

	return 0;
}