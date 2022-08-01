#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void hanoi(int n, int from, int by, int to) {

	if (n == 0) return;
	hanoi(n - 1, from, to, by);
	printf("%d %d\n", from, to);
	hanoi(n - 1, by, from, to);

}

int main(void)
{
	int N, total = 1;
	scanf("%d", &N);

	printf("%d\n", (int)pow(2.0, double(N)) - 1);
	hanoi(N, 1, 2, 3);
	return 0;
}