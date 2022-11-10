#include <iostream>
#include <cmath>

using namespace std;

int counts[50001];	//각 수의 최소 제곱수 개수 저장.

int getCount(int num) {		//num의 최소 제곱수를 계산해 반환
	//이미 계산한 적 있다면?
	if (counts[num] != 0) return counts[num];

	//정수의 제곱으로 나타내지면 그냥 1이다.
	int temp = sqrt(num);		
	if (pow(temp, 2) == num) return counts[num] = 1;

	bool signal = false;		//가능한 것 있는지 여부
	int minValue = 9999999;
	for (int i = temp; i >= 1; i--) {		
		if (getCount(num - pow(i, 2)) != 0) {
			signal = true;
			minValue = min(minValue, getCount(num - pow(i, 2)));
		}
	}
	if (!signal) 
		return counts[num] = 0;		//가능한 것이 없으면 0리턴.
	else 
		return counts[num] = (minValue+1);
}

int main() {
	int n;
	cin >> n;

	cout << getCount(n) << endl;

	return 0;
}