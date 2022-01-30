
#include <iostream>

using namespace std;

long long getLength(int n) {
  long long dp[81];   //한 변의 길이 저장

  if (n == 1) return 4;
  else if (n == 2) return 6;
  else if (n == 3) return 10;
  else if (n == 4) return 16;

  dp[1] = 1; dp[2] = 1; dp[3] = 2; dp[4] = 3;
  
  for (int i = 5; i <= n; i++) {
    dp[i] = dp[i-1] + dp[i-3] + dp[i-4];
  }

  //n번째 일때 둘레의 길이는?? (n번째 타일 한변 길이 * 3) + (n-1번째 * 2) + (n-2번쨰 * 2) + (n-3번째 * 1)
  return (3*dp[n]) + (2*dp[n-1]) + (2*dp[n-2]) + dp[n-3];

}

int main() {
  int n;
  cin >> n;

  cout << getLength(n) << endl;
  
  return 0;
}