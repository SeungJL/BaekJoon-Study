#include <iostream>
#include <queue>	

using namespace std;

int M, N;
int status[1000][1000];
int not_rotten_tomato = 0;
queue<pair<int,int>> q;

int bfs() {
	int days = 0;
	pair<int,int> now;
	while (!q.empty()) {
		now = q.front();
		q.pop();
		if (now.first == -9999 && now.second == -9999) {		//날짜 구분을 꺼냈을경우
			if (q.empty())
				break;
			else {
				days++;
				q.push({-9999,-9999});
			}
		}
		else {
			if (now.first-1 >= 0 && status[now.first-1][now.second] == 0){
				status[now.first-1][now.second] = 1;	
				q.push({now.first-1, now.second});
				not_rotten_tomato--;
			}
			if (now.first+1 < N && status[now.first+1][now.second] == 0){
				status[now.first+1][now.second] = 1;	
				q.push({now.first+1, now.second});
				not_rotten_tomato--;
			}
			if (now.second-1 >= 0 && status[now.first][now.second-1] == 0){
				status[now.first][now.second-1] = 1;	
				q.push({now.first, now.second-1});
				not_rotten_tomato--;
			}
			if (now.second+1 < M && status[now.first][now.second+1] == 0) {
				status[now.first][now.second+1] = 1;
				q.push({now.first, now.second+1});
				not_rotten_tomato--;
			}
		}
	}
	return days;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N;
	int temp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> temp;
			status[i][j] = temp;
			if (temp == 1) 
				q.push({i, j});
			if (temp == 0)
				not_rotten_tomato++;
		}
	}
	q.push({-9999,-9999});		//구분하는 용도

	int result = bfs();
	if (not_rotten_tomato > 0) 		//익지 않은 토마토가 남아있다면,
		cout << -1 << endl;
	else
		cout << result << endl;
	return 0;
}

