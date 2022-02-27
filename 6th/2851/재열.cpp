#include <iostream>

using namespace std;

int main() {
	int mushrooms[10];

	for (int i = 0; i < 10; i++) {
		cin >> mushrooms[i];
	}

	int sum = 0;
	int i = 0;
	int result;
	while (sum < 100 && i < 10) {
		sum += mushrooms[i];
		i++;
	}
	if (sum == 100 || i == 0)	{
		result = sum;
	}
	else {
		int temp = sum - mushrooms[--i];		//sum은 가까운 수 중 큰것, temp는 가까운 수 중 작은것
		if (sum - 100 <= 100 - temp)
			result = sum;
		else 
			result = temp;
	}

	cout << result << endl;

	return 0;
}