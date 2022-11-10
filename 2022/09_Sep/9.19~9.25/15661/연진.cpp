#include <iostream>
using namespace std;

int N;
int arr[20][20];

void makePair(int a, int b)
{
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cin >> arr[i][j];
    }
  }

  // for (int i = 2; i <= N / 2; i++)
  // {
  //   makePair();
  // }

  return 0;
}