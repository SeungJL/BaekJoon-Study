// https://hio9105.tistory.com/entry/BOJ-3980-%EC%84%A0%EB%B0%9C-%EB%AA%85%EB%8B%A8-backtracking-bruteforcing

#include <iostream>
using namespace std;

int stat[11][11] = {};	// input으로 주어지는 포지션의 따른 각 선수의 능력치
int perm[11] = {};		// 선수 배치 조합
int max_stat = 0;		// 팀 능력치 최댓값

/* solve: 선수 배치 조합을 구하고, 팀 능력치의 최댓값을 구하는 함수 
 *
 * parameters - player: 0-10 번 중 포지션을 배치할 선수 번호
 *            - visited: 이미 선수를 배치한 포지션 정보
 *            - team_stat: player-1까지 배치했을 때의 팀 능력치 
 * no return
 */
void solve(int player, int visited, int team_stat) {
	if (player == 11) {	// 모든 선수를 배치했을 때
		if (team_stat > max_stat) max_stat = team_stat;
		return;
	}

	for (int pos=0; pos<11; pos++) {
		if ((visited & (1 << pos)) != 0) continue;	// 이미 선수를 배치한 포지션일 경우
		if (stat[player][pos] == 0) continue;		// 해당 포지션에서의 선수의 능력치가 0인 경우
		solve(player+1, visited | (1 << pos), team_stat + stat[player][pos]);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen("input.txt", "rt", stdin);

	int TC;
	
	cin >> TC;
	while (TC--) {
		/* init & input*/
		for (int i=0; i<11; i++) {
			for (int j=0; j<11; j++)
				cin >> stat[i][j];
		}
		max_stat = 0;

		/* solve */
		solve(0, 0, 0);
		cout << max_stat << "\n";
	}

}
