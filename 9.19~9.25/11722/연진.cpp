#include <iostream>
#include <map>
using namespace std;

int main()
{
  int N;
  int arr[1000];
  map<int, int> m; // <n, n이후 수열 길이>
  /* 입력받기 */
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    int k;
    cin >> k;
    arr[i] = k;
  }

  for (int i = N - 1; i >= 0; i--)
  {
    int longest = 0; // arr[i] 보다 작은 원소의 최댓값
    map<int, int>::iterator it;
    for (it = m.begin(); it != m.end(); ++it)
    {
      if (it->first < arr[i])
      {
        longest = longest < it->second ? it->second : longest;
      }
    }
    if (m.count(arr[i]))
    {
      m[arr[i]] = longest + 1 > m[arr[i]] ? longest + 1 : m[arr[i]];
    }
    else
    { // 해당 값이 map에 존재하지 않으면
      m.insert(make_pair(arr[i], longest + 1));
    }
  }

  int answer = 1;
  map<int, int>::iterator it;
  for (it = m.begin(); it != m.end(); ++it)
  {
    if (answer < it->second)
    {
      answer = it->second;
    }
  }
  cout << answer;

  return 0;
}