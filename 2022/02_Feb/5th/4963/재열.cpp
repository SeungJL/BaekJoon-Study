#include <iostream>

using namespace std;

int graph[51][51];
bool isVisited[51][51];
int w, h, cnt;

void dfs(int y, int x) {
	if (y < 0 || y >= h || x < 0 || x > w) return;		

	if (graph[y][x] == 0 || isVisited[y][x] == true) return;	
	else {
		isVisited[y][x] = true;
		cnt++;
		dfs(y-1, x-1);	//왼쪽위
		dfs(y-1, x);		//위
		dfs(y-1, x+1);	//오른쪽위
		dfs(y, x-1);		//왼쪽
		dfs(y, x+1);		//오른쪽
		dfs(y+1, x-1);		//왼쪽아래
		dfs(y+1, x);		//아래
		dfs(y+1, x+1);		//오른쪽아래
	}
}


int main() {
	while (true) {
		for (int i = 0; i < 51; i++) {
			for (int j = 0; j < 51; j++) {
				graph[i][j] = 0;
				isVisited[i][j] = false;
			}
		}
		
		int islandCount = 0;	

		cin >> w >> h;
		if (w == 0 && h == 0) break;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> graph[i][j];
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (graph[i][j] == 1 && !isVisited[i][j]) {
					cnt = 0;		
					dfs(i, j);
					if (cnt > 0) islandCount++;
				}	
			}
		}

		cout << islandCount << endl;
	}
	return 0;
}