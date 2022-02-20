#include <iostream>
#include <vector>

using namespace std;

int main() {
	int L, N;
	cin >> L >> N;

	vector<int> cake(L+1);

	int max1 = -1;		//가장 많은 조각을 받을 것으로 기대하고 있던 방청객의 조각
	int maxIndex1;		//가장 많은 조각을 받을 것으로 기대하고 있던 방청객의 번호
	int max2 = -1;		//실제로 가장 많은 조각을 받은 방청객의 조각
	int maxIndex2;		//실제로 가장 많은 조각을 받은 방청객의 번호
	for (int i = 1; i <= N; i++) {
		int p, k;
		cin >> p >> k;
		if (k - p + 1 > max1) {
			maxIndex1 = i;
			max1 = k - p + 1;
		}
		int realCount = 0;	
		for (int j = p; j <= k; j++) {		
			if (cake[j] == 0) {
				cake[j] = i;
				realCount++;
			}
		}
		if (realCount > max2) {
			maxIndex2 = i;
			max2 = realCount;
		}
	}

	cout << maxIndex1 << '\n' << maxIndex2 << endl;
	return 0;
}
