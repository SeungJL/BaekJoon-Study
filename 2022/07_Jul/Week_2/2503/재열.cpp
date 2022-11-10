#include <iostream>

using namespace std;

int num_1(int num) {		
	return num / 100;
}
int num_2(int num) {		
	num = num % 100;
	return num / 10;
}
int num_3(int num) {		
	num = num % 100;
	num = num % 10;
	return num;
}

int strike_count(int test, int target) {
	int count = 0;
	if (num_1(test) == num_1(target))	count++;
	if (num_2(test) == num_2(target))	count++;
	if (num_3(test) == num_3(target))	count++;
	return count;
}
int ball_count(int test, int target) {
	int count = 0;
	if (num_1(test) != num_1(target) && (num_1(test) == num_2(target) || num_1(test) == num_3(target)))
		count++;
	if (num_2(test) != num_2(target) && (num_2(test) == num_1(target) || num_2(test) == num_3(target)))
		count++;
	if (num_3(test) != num_3(target) && (num_3(test) == num_1(target) || num_3(test) == num_2(target)))
		count++;
	return count;
}

int main() {
	int N;
	cin >> N;
	int all_nums[1000] = {0,};
	int num, strikes, balls;
	int n1, n2, n3;
	for (int i = 0; i < N; i++) {
		cin >> num >> strikes >> balls;
		for (int j = 111; j <= 999; j++) {
			if (num_1(j) == num_2(j) || num_1(j) == num_3(j) || num_2(j) == num_3(j))
				continue;
			if (num_1(j) == 0 || num_2(j) == 0 || num_3(j) == 0)	
				continue;
			if (strike_count(num, j) == strikes && ball_count(num, j) == balls)
				all_nums[j]++;
		}
	}
	int result = 0;
	for (int j = 111; j <= 999; j++) {
		if (all_nums[j] == N) 
			result++;
	}
	cout << result << endl;
	return 0;
}
