// 백준 16922번 로마 숫자 만들기 
#include <iostream>

using namespace std;

int main() {
	
	int num;
	cin >> num;

	bool sum[50 * 20 + 1] = { 0, }; // index = 값
	int result = 0;
	
	for(int i=0; i <= num; i++)
		for(int j=0; j<= num-i; j++)
			for (int k = 0; k <= num-i-j; k++) {
				int l = num - (i + j + k);
				sum[i + (5 * j) + (10 * k) + (50 *l)] = true;
			}

	for (int i = 1; i <= 50 * 20; i++) {
		if (sum[i] == true)
			result += 1;
	}

	cout << result << endl;

	return 0;
}
