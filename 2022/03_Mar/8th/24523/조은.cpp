#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<int> v(N+1), ans(N+1, -1);
	for(int i=1; i<=N; i++) cin >> v[i];
	
	for(int i=1; i<=N-1; )  {
		bool flag = false;
		int j;
		for(j=i+1; j<=N; j++) {
			if(v[i] != v[j]) {
				cout << j << ' ';
				flag = true;
				break;
			}
		}
		if(flag) { // i���� ~ (j-1)���� �� �Ȱ�
			for(int k=i+1; k<j; k++)
				cout << j << ' ';
			i = j;
		}
		else { // i��°���� ������ �� ���� ���� ���
			for(int k=i; k<N; k++)
				cout << -1 << ' ';
			break;
		}
	}
	cout << -1;

	return 0;
}