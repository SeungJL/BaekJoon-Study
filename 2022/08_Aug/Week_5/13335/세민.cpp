#include <iostream>
#include <queue>

using namespace std;

constexpr int MAX = 1001;
int a[MAX];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, w, L;	//트럭의 수, 다리의 길이, 다리의 최대하중
	cin >> n >> w >> L;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	queue<int> q;
	int sum = 0, T = 0; //트럭 무게의 합, 시간

	for (int i = 0; i < n; ++i) {
		while (true) {
			if (q.empty()) { //다리에 트럭이 없다면
				q.push(a[i]);
				T++;
				sum += a[i];
				break;
			}
			else if (q.size() == w) {	//큐의 크기가 다리의 길이와 같다면
				sum -= q.front(); //맨 앞의 트럭의 무게만큼 감소
				q.pop(); //맨 앞의 트럭을 큐에서 삭제
			}
			else { //다리에 트럭이 있다면
				if (sum + a[i] > L) { //다리를 건너려는 트럭 무게와 다리 위 트럭 무게의 합이 다리의 최대하중보다 크다면	
					q.push(0);
					T++;
				}
				else { //최대하중보다 작다면
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