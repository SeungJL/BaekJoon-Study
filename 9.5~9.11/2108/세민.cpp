#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int arr[500001] = { 0, };
int cnt[8001] = { 0, };

int main(void)
{
	int N, sum = 0, mode = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
		cnt[arr[i] + 4000]++;
	}
	
	double avg = round((double)sum / N);

	sort(arr, arr + N);

	int flag, max = 0;
	for (int i = 0; i < 8001; i++) {
		if (cnt[i] > max) {
			max = cnt[i];
			flag = i;
		}
	}
	for (int i = flag + 1; i < 8001; i++) {
		if (cnt[i] == max) {
			flag = i;
			break;
		}
	}
	
	printf("%.0lf\n", avg);
	printf("%d\n", arr[(N - 1) / 2]);
	printf("%d\n", flag - 4000);
	printf("%d\n", arr[N - 1] - arr[0]);

	return 0;
}