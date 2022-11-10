#include <iostream>
#include <queue>

using namespace std;

constexpr int MAX = 1001;
int a[MAX];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, w, L;	//Ʈ���� ��, �ٸ��� ����, �ٸ��� �ִ�����
	cin >> n >> w >> L;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	queue<int> q;
	int sum = 0, T = 0; //Ʈ�� ������ ��, �ð�

	for (int i = 0; i < n; ++i) {
		while (true) {
			if (q.empty()) { //�ٸ��� Ʈ���� ���ٸ�
				q.push(a[i]);
				T++;
				sum += a[i];
				break;
			}
			else if (q.size() == w) {	//ť�� ũ�Ⱑ �ٸ��� ���̿� ���ٸ�
				sum -= q.front(); //�� ���� Ʈ���� ���Ը�ŭ ����
				q.pop(); //�� ���� Ʈ���� ť���� ����
			}
			else { //�ٸ��� Ʈ���� �ִٸ�
				if (sum + a[i] > L) { //�ٸ��� �ǳʷ��� Ʈ�� ���Կ� �ٸ� �� Ʈ�� ������ ���� �ٸ��� �ִ����ߺ��� ũ�ٸ�	
					q.push(0);
					T++;
				}
				else { //�ִ����ߺ��� �۴ٸ�
					q.push(a[i]);
					T++;
					sum += a[i];
					break;
				}
			}
		}
	}

	cout << T + w;

	return 0;
}