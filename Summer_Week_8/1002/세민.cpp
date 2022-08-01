#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int T;
	scanf("%d", &T);
	int x1, y1, r1, x2, y2, r2;
	for (int i = 0; i < T; i++) {
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		int d = (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);
		if ((r2 - r1)*(r2 - r1) > d) {
			printf("0\n");
		}
		else if ((r2 - r1)*(r2 - r1) == d && d != 0) {
			printf("1\n");
		}
		else if ((r2 + r1)*(r2 + r1) == d && d != 0) {
			printf("1\n");
		}
		else if ((r2 + r1)*(r2 + r1) < d) {
			printf("0\n");
		}
		else if (r1 == r2 && d == 0) {
			printf("-1\n");
		}
		else {
			printf("2\n");
		}
	}

	return 0;
}