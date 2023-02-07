// 10844
#include<iostream>
#define X 1000000000

using namespace std;

int N;
long long dp[101][10];


int main(){
  cin >> N;
  dp[1][0] = 0;
  for(int i = 1; i<=9; i++){
    dp[1][i] = 1;
  }
  
  for(int i = 2; i<=N; i++){
    for(int j = 1; j<=8; j++){
      dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % X;
    }
    dp[i][0] = (dp[i-1][1]) % X;
    dp[i][9] = (dp[i-1][8]) % X;
  }
  
  long long sum = 0;
  for(int i=0; i<=9; i++){
      sum += dp[N][i];
  }
  
  cout << sum % X ;
}

// 예를 들어 3자리수인 경우
// 1 -> (0 또는 2) -> 0인 경우 (1) / 2인 경우 (1 또는 3)