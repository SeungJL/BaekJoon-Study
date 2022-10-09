#include <iostream>
#include <vector>
#include <array>
using namespace std;

int main()
{
  int N;
  vector<array<int, 3> > arr;
  cin >> N;
  for(int i=0;i<N;i++){
    array<int, 3> temp;
    cin >> temp[0] >> temp[1] >> temp[2];

    arr.push_back(temp);
  }

  int max_score, min_score;
  int min[3]; // 각 줄의 최솟값 누적합
  int max[3]; // 각 줄의 최댓갑 누적합

  for (int i = 0; i < 3; i++)
  {
    min[i] = arr[0][i];
    max[i] = arr[0][i];
  }

  for (int i = 1; i < N; i++)
  {
    int left_min, right_min, left_max, right_max;
    left_min = min[0] < min[1] ? 0 : 1;
    left_max = max[0] > max[1] ? 0 : 1;
    right_min = min[1] < min[2] ? 1 : 2;
    right_max = max[1] > max[2] ? 1 : 2;
    // a b c 한 행에서
    /*  a  */
    min[0] = arr[i][0] + min[left_min];
    max[0] = arr[i][0] + max[left_max];

    min[2] = arr[i][2] + min[right_min];
    max[2] = arr[i][2] + max[right_max];

    min[1] = arr[i][1] + min[left_min < right_min ? left_min : right_min];
    max[1] = arr[i][1] + max[left_max > right_max ? left_max : right_max];
  }

  min_score = min[0] < min[1] ? min[0] : min[1];
  min_score = min[2] < min_score ? min[2] : min_score;

  max_score = max[0] > max[1] ? max[0] : max[1];
  max_score = max[2] > max_score ? max[2] : max_score;

  cout << max_score << " " << min_score;

  return 0;
}