#include <iostream>

using namespace std;

int n;
int num[1001] = {0,};   //각 칸의 숫자
int minDepthInfo[1001] = {0,};   //각 칸에서 최소 횟수 정보 저장

//해당 인덱스 거쳤을 때의 횟수를 지금까지 횟수에 더해서 반환  (만약 끝을 방문하지 않는다면 -1리턴)
int dfs(int index, int depth) {
  if (index > n) return -1;
  if (index == n) return depth;

  if (minDepthInfo[index] == -1) return -1;   //이미 경로가 없다는게 확정되었으면
  if (minDepthInfo[index] != 0) return depth + minDepthInfo[index];   //이미 구한적이 있다면

  int min;
  int minIndex;
  bool signal = false;  // min에 담은 것이 있는지 여부
  for (int i = 1; i <= num[index]; i++) {   //이 점에서 점프 가능한 칸 중 일단 어떤 칸으로 이동했을 때 가장 횟수가 적을지 탐색
    int value = dfs(index + i, depth+1);  
    if (value != -1) {
      value -= depth;   //뺀 이유: 반환값은 현재 칸까지 들어간 횟수도 포함하기 때문
      if (!signal) {
        min = value;  
        minIndex = i;
        signal = true;
      }
      else {
        if (value < min) {
          min = value;  
          minIndex = i;
        } 
      }
    }
  }
  if (!signal) return minDepthInfo[index] = -1;   //가능한 아무 경로도 없는 경우

  minDepthInfo[index] = min;
  return min + depth;
}

int main() {
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> num[i];
  }

  cout << dfs(1, 0) << endl;

  return 0;
}