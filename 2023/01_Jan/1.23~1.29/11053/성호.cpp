#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning(disable : 4996)

using namespace std;

int main()
{
  int T;
  int N, M, K, H;
  int X, Y;
  int answer = 0;

  int dp[1001];
  vector<int> v;
  cin >> T;

  for (int i = 0; i < T; i++)
  {
    cin >> K;
    v.emplace_back(K);
    int dp_max = 0;

    for (int j = 0; j < v.size(); j++)
    {
      if (v[i] > v[j])
      {
        if (dp_max < dp[j])
          dp_max = dp[j];
      }
    }
    dp[i] = dp_max + 1;
    answer = max(answer, dp[i]);
  }

  cout << answer << endl;

  return 0;
}