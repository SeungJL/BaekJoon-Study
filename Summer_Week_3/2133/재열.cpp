#include <iostream>

using namespace std;

int dp[1001] = {0,};

int cases(int n) {
  if (n == 0) return 1;
  if (n == 1) return 0;
  if (n == 2) return 3;

  if (dp[n] != 0) return dp[n];

  int sum = 0;
  sum += 3 * cases(n-2);
  for (int i = n-4; i >= 0; i -= 2) {
    sum += (2 * cases(i));
  }
  return dp[n] = sum;
}

int main() {
  int n;
  cin >> n;

  cout << cases(n) << endl;

  return 0;
}

