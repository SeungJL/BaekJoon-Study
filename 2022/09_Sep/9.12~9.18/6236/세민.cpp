#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

constexpr int MAX = 100'001;

int a[MAX];
int N, M, sum = 0, ans = 0;

bool check(int mid)
{
	int idx = 1, Tot = mid;
	for (int i = 1; i <= N; ++i) {
		if (mid < a[i]) return false;	//���� �ݾ��� �Ϸ� ��� �ݾ׺��� ���ٸ� 

		if (Tot < a[i]) {
			Tot = mid;
			idx++;
		}
		Tot -= a[i];
	}
	return M >= idx;
}

void binary_search()
{
	int low = 1, mid, high = sum;
	while (low <= high) {	
		mid = (low + high) / 2;
		if (check(mid)) {
			ans = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	cout << ans;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// freopen("input.txt", "r", stdin);
	cin >> N >> M;

	for (int i = 1; i <= N; ++i) {
		cin >> a[i];
		sum += a[i];
	}

	binary_search();

	return 0;
}