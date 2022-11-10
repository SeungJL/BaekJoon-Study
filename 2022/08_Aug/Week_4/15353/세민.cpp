#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int arr[10001], p = 0, n1, n2, idx = 0;
	string A, B;
	cin >> A >> B;
	int a_len = A.length(), b_len = B.length();
	while (a_len || b_len || p) {
		if (a_len) n1 = A[(a_len--) - 1] - '0';
		if (b_len) n2 = B[(b_len--) - 1] - '0';
		arr[idx++] = (n1 + n2 + p) % 10;
		p = n1 + n2 + p > 9 ? 1 : 0;
		n1 = n2 = 0;
	}
	for (int i = idx - 1; i >= 0; --i) {
		cout << arr[i];
	}

	return 0;
}