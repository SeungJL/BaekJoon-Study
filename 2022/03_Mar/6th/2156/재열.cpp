#include <iostream>
#include <algorithm>

using namespace std;

int value[10001];		//각 인덱스의 포도주 양
int drink[10001];		//각 인덱스에 있는 포도주를 마셨을 때 각 인덱스까지의 최댓값
int noDrink[10001];			//각 인덱스에 있는 포도주를 마시지 않았을 때 각 인덱스까지의 최댓값

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> value[i];
	}

	drink[1] = value[1];
	noDrink[1] = 0;

	drink[2] = drink[1] + value[2];
	noDrink[2] = drink[1];

	for (int i = 2; i <= n; i++) {
		noDrink[i] = max(drink[i-1], noDrink[i-1]);
		drink[i] = max(noDrink[i-2] + value[i-1] + value[i], noDrink[i-1] + value[i]);
	}

	cout << max(drink[n], noDrink[n]) << endl;

	return 0;
}