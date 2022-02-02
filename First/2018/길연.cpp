// 백준 2018번 
#include <iostream>
using namespace std;

int main() {
	
	int count = 1; // 자기 자신 포함
	int num = 0;

	cin >> num;


	for (int i = 1; i <= num / 2 ; i++)
	{
		int sum = 0;
	
		for (int j = i; j <= num / 2+1; j++)
		{
			sum += j;

			if (sum == num) {
				count += 1;
				break;
			}

			if (sum > num) {
				break;
			}
		}
	}
	

	cout << count << endl;

	return 0;

}
