#include <iostream>

using namespace std;

bool hasBlock[101][101][101];

int main() {
	int N, M;
	cin >> N >> M;
	
	int sum = 0;
	sum += (N * M * 2);		

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int num;
			cin >> num;
			for (int k = 0; k < num; k++) {		
				hasBlock[i][j][k] = true;
				if ((i == 0 || !hasBlock[i-1][j][k]) && (i == N-1 || !hasBlock[i+1][j][k]))
					sum += 2;
				if ((j == 0 || !hasBlock[i][j-1][k]) && (j == M-1 || !hasBlock[i][j+1][k]))
					sum += 2;
			}
		}
	}

	cout << sum << endl;
	return 0;
}