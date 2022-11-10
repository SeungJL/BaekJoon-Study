// 백준 8979번 올림픽
// 2022년 01월 25일

#include <iostream>

using namespace std;

int main() {

	int num, target;
	cin >> num >> target;

	int index = 0;
	int gold[1001], sliver[1001], bronze[1001];
	int rank = 1;  // target이 제일 잘한경우 1등, 1등부터 밀려남

	for (int i = 0; i < num; i++) {		
		cin >> index;
		cin >> gold[index] >> sliver[index] >> bronze[index];		
	}
	
	for (int i = 1; i <= num; i++) { // target보다 잘한애들만 생각해주기 등수++되면 밀려난다는 뜻
		if(gold[i] > gold[target])
			rank += 1;
		else if (gold[i] == gold[target]) {
			if (sliver[i] > sliver[target])
				rank += 1;
			else if (sliver[i] == sliver[target]) {
				if (bronze[i] > bronze[target])
					rank += 1;
			}
		}
	}

	cout << rank;
	return 0;
}
