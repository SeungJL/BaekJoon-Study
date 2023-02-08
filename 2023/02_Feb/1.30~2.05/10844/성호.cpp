#include <iostream>
using namespace std;

long long arr[101][10] = {
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    0,
};
int main(void)
{
  int n;
  cin >> n;
  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      if (j - 1 < 0)
        arr[i][j] = arr[i - 1][j + 1] % 1000000000;
      else if (j + 1 > 9)
        arr[i][j] = arr[i - 1][j - 1] % 1000000000;
      else
        arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j + 1] % 1000000000;
    }
  }
  long long ans = 0;
  for (int i = 1; i <= 9; i++)
  {
    ans += arr[n - 1][i];
  }
  cout << ans % 1000000000 << endl;
  return 0;
}