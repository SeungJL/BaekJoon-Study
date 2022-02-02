#include <iostream>

using namespace std;

bool table[102][102];    //각 칸마다 음식물 있는지 나타냄
bool isVisited[102][102];   //방문한적 있는지 체크

//자기 차례까지 왔을때 음식물의 개수 반환
int dfs(int a, int b, int count) {
  if (isVisited[a][b]) return count;


  isVisited[a][b] = true;
  count++;
  
  int countSum = count;
  //상
  if (table[a-1][b]) {
    countSum += (dfs(a-1, b, count) - count);   //count를 빼는 이유: countSum값에 count값은 한번만 포함시키기 위해
  }
  //하
  if (table[a+1][b]) {
    countSum += (dfs(a+1, b, count) - count);
  }
  //좌
  if (table[a][b-1]) {
    countSum += (dfs(a, b-1, count) - count);
  }
  //우
  if (table[a][b+1]) {
    countSum += (dfs(a, b+1, count) - count);
  }

  return countSum;
}


int main() {
  int n, m, k;
  cin >> n >> m >> k;


  for (int i = 0; i <= n+1; i++) {
    for (int j = 0; j <= m+1; j++) {
      table[i][j] = false;
      isVisited[i][j] = false;
    }
  }

  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    table[a][b] = true;
  }

  int maxCount = 0;
  //각 점마다 dfs를 수행하여 그 점으로부터 출발했을때의 음식물 크기 구함.
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (!table[i][j] || isVisited[i][j]) continue;    
      int value = dfs(i, j, 0);
      if (value > maxCount) maxCount = value;
    }
  }
  cout << maxCount << endl;
  return 0;
}