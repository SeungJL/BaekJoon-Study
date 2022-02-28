#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[10001] = { 0 };
int dp[10001]; // dp[n]: n��° �����ֱ��� �ִ�� ���� �� �ִ� ��

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}

	for(int i=0; i<=n; i++) {
		if(i<=2) { // �ʱⰪ ����
			for(int j=0; j<=i; j++)
				dp[i] += a[j];
		}
		else { // ��ȭ��
			dp[i] = dp[i-3] + a[i-1] + a[i];
			dp[i] = max(dp[i], dp[i-2] + a[i]);
			dp[i] = max(dp[i], dp[i-1]);
		}
	}

	cout << endl;
	for (int i = 0; i <= n; i++) cout << dp[i] << endl;

	cout << endl;
	cout << dp[n];
	
	return 0;
}