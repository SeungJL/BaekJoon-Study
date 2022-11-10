// 백준 10451 순열 사이클 ! 틀림 !

#include <iostream>
using namespace std;

int main()
{

  int T; // 테스크 케이스
  cin >> T;

  while (T--)
  {
    int N;         // 순열 크기
    int arr[1002]; // 순열
    bool visited[1002];
    cin >> N;
    arr[0] = 0;

    for (int i = 1; i <= N; i++)
    {
      int k;
      cin >> k;
      arr[i] = k;
      visited[i] = false;
    }
    visited[N + 1] = false;

    int ping = 1; // 시작점 마크
    int tar = 1;  // 현위치
    int answer = 0;

    do
    {
      tar = ping; // 시작점 업데이트
      while (!visited[tar])
      {
        visited[tar] = true; // 지났던 지점 0으로
        tar = arr[tar];      // 루프
      }
      answer++;
      while (visited[ping] && ping <= N + 1)
      {
        ping++;
      } // ping 업데이트
    } while (!visited[ping]);
    cout << answer;
  }

  return 0;
}