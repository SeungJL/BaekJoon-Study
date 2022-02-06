#include <iostream>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	bool graph[n][m];

	//입력받기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char val;
			cin >> val;
			if (val == '.') 
				graph[i][j] = false;
			else		
				graph[i][j] = true;
		}
	}

	int count = 0;

	//가로 방향으로 탐색
	for (int i = 0; i < n; i++) {
		int rowSignal = false;
		for (int j = 0; j < m; j++) {
			if (graph[i][j]) {		//[i][j]번째 칸에 경비원 있다면? 안쪽 for문 break
				rowSignal = true;
				break;
			}		
		}
		if (!rowSignal) {
			for (int j = 0; j < m; j++) {
				//[i][j]번째 칸이 비어있다면? 해당 칸의 세로줄을 본다. 세로줄 전체가 비어있다면 경비원 배치. 안쪽for문을 break
				bool signal = false;
				for (int k = 0; k < n; k++) {
					if (graph[k][j]) {
						signal = true;
						break;
					}
				}
				if (!signal) {
					graph[i][j] = true;
					rowSignal = true;
					break;
				}	
			}
			count++;
		} 
	}

	//여기까지만 하면, 세로줄에 아무것도 없는 케이스 있을 수 있다.
	//어떤 세로 줄에 아무 경비원도 없는거 발견시 count추가
	for (int i = 0; i < m; i++) {		//i번째 세로줄에 대해
		bool signal = false;
		for (int j = 0; j < n; j++) {
			if (graph[j][i]) {
				signal = true;
				break;
			}
		}
		if (!signal) 
			count++;
	}

	cout << count << endl;

	return 0;
}