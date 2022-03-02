#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

int S[21][21];
int N;
int minValue = 9999999;

bool already[21];		
bool check1[21][21];
bool check2[21][21];

//dfs는 N개 중 N/2개의 조합을 만들 목적(+ 조합을 완성하면 팀의 능력치 차이도 구하여 최솟값과 비교함)으로 수행한다.
void dfs(int now, int depth) {		
	already[now] = true;

	if (depth == N/2) {
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= N; j++) {
				check1[i][j] = false;
				check2[i][j] = false;
			}
		}
		int team1_sum = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (!check1[i][j] && already[i] && already[j]) {
					team1_sum += S[i][j];
					check1[i][j] = true;
				}
			}
		}
		int team2_sum = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (!check2[i][j] && !already[i] && !already[j]) {
					team2_sum += S[i][j];
					check2[i][j] = true;
				}
			}
		}
		int value = max(team1_sum, team2_sum) - min(team1_sum, team2_sum);
		minValue = min(value, minValue);
	}
	else {
		for (int i = now+1; i <= N; i++) {		//now부터만 탐색! 중복으로 인한 시간 증가 방지
			if (!already[i]) 
				dfs(i, depth + 1);
		}
	}
	already[now] = false;		//자신을 불렀던 함수로 돌아가므로 상태 복원을 해야함.
}

int main() {
	cin >> N;
	
	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= N; j++) 
			cin >> S[i][j];
	
	fill(already, already + N+1, false);
	dfs(0, 0);		

	cout << minValue << endl;

	return 0;
}