// 1495] 기타리스트
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false); 
  cin.tie(0); cout.tie(0);
  freopen("input.txt", "rt", stdin);

  // 곡의 개수, 시작 볼륨, 불륨의 최댓값
  int n, s, m; 
  int vol[110];
  // n번째 곡일 때, 볼륨 s 가능 여부
  int dp[110][1100];
  
  cin >> n >> s >> m;
  for(int i=1; i<=n; i++) {
    cin >> vol[i];
  }

  // 첫 번째 곡
  if(s+vol[1] <= m) dp[1][s+vol[1]] = 1;
  if(s-vol[1] >= 0) dp[1][s-vol[1]] = 1;

  // 두 번째 곡부터 계산
  for(int i=2; i<=n; i++) {
    for(int j=0; j<=m; j++) {
      if(dp[i-1][j] == 1) {
        if(j+vol[i] <= m) dp[i][j+vol[i]] = 1;
        if(j-vol[i] >= 0) dp[i][j-vol[i]] = 1;
      }
    }
  }
  
  for(int i=m; i>=0; i--) {
    if(dp[n][i] == 1) {
      cout << i << "\n";
      return 0;
    }
  }
  cout << "-1\n";
  
  return 0;
}
