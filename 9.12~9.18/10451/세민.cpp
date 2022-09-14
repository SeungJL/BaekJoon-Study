#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

constexpr int MAX = 1001;	//������ �ִ� ũ�� : 1000

int arr[MAX];
bool visited[MAX];

bool is_cycle(int from)
{
	visited[from] = true;
	if (visited[arr[from]]) return true;	//�̹� �湮�� ��带 ��湮�ϴ� ��� ����Ŭ�� ����
	return is_cycle(arr[from]);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// freopen("input.txt", "r", stdin);

	int T;	//�׽�Ʈ ���̽��� ����
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int N;
		cin >> N;
		for (int i = 1; i <= N; ++i) {
			int num;
			cin >> num;
			arr[i] = num;
			visited[i] = false;
		}

		int ans = 0;	//���� ����Ŭ�� ����
		for (int i = 1; i <= N; ++i) {
			if (!visited[i]) {
				if (is_cycle(i)) ans++;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}