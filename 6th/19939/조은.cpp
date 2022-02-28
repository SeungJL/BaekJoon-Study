#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	int total=0; // �ٱ��Ͽ� ���� ������ �� ����
	for (int i = 1; i <= k; i++) {
		// �ϴ� ó���� k���� �ٱ����� ���� 1,2,...k���� �ִ´ٰ� ����
		total += i;
	}

	if(total > n) {
		cout << -1;
		return 0;
	}
	else if((n-total)%k == 0) {
		cout << k-1;
		return 0;
	}
	else {
		cout << k;
		return 0;
	}

	return 0;
}