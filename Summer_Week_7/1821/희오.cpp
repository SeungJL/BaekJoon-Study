// BOJ 1821

#include <iostream>

using namespace std;

int N, F;
int cnt[10][10] = {{1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				   {1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
				   {1, 2, 1, 0, 0, 0, 0, 0, 0, 0},
				   {1, 3, 3, 1, 0, 0, 0, 0, 0, 0},
				   {1, 4, 6, 4, 1, 0, 0, 0, 0, 0},
				   {1, 5, 10, 10, 5, 1, 0, 0, 0, 0},
				   {1, 6, 15, 20, 15, 6, 1, 0, 0, 0},
				   {1, 7, 21, 35, 35, 21, 7, 1, 0, 0},
				   {1, 8, 28, 56, 70, 56, 28, 8, 1, 0},	
				   {1, 9, 36, 84, 126, 126, 84, 36, 9, 1}};
int per[10];

bool check_res() {
	int sum = 0;
	for(int i=0; i<N; i++) {
		sum += cnt[N-1][i] * per[i];
        if (sum > 1000000) return false;
	}
	if (sum == F) {
        for (int i=0; i<N; i++) cout << per[i] << " ";
        return true;
    }
	else return false;
}

void DFS_permutation(int k, int visited) {
	if (k == N) {
		if (check_res()) exit(0);
		return ;
	}

	for (int i=1; i<=N; i++) {
		if ((visited & (1 << i)) == 0) {
			per[k] = i;
			DFS_permutation(k+1, visited | (1 << i));
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

//	freopen("input.txt", "rt", stdin);

	cin >> N >> F;
	DFS_permutation(0, 0);
} 