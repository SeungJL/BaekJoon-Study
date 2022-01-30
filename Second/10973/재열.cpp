#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void swap(vector<int>& v, int a, int b) {
  int temp = v[a];
  v[a] = v[b];
  v[b] = temp;
}

bool compare(int a, int b) {    //정렬할 때 사용할 예정
  return a > b;
}

int main() {
  int n;
  cin >> n;

  vector<int> permutation(n);
  for (int i = 0; i < n; i++) {
    cin >> permutation[i];
  }

  //가장 뒷부분 값부터 바로 앞 값이랑 바꾸려고 시도.
  //이미 뒤의 값이 더 크다? 그 바로 전 값을 바로 앞 값이랑 바꾸려고 시도. (단, 만약 바꿈이 성사되면, 뒤의 값들을)
  //만약 앞 값이 뒷값보다 작은 케이스가 하나도 없다? 그럼 -1. 

  int idx = n-1;  //idx은 현재 인덱스 (가장 뒤부터 시작)
  while (true) {
    if (idx == 0) break;
    
    if (permutation[idx-1] > permutation[idx]) {
      //어떤 값과 바꿀지 탐색 (뒤에 있는 permutation[idx-1]보다 작은 최댓값. 즉 뒤에서부터 탐색해서 대상보다 작은 값 있으면 바로 그거.)
      int temp = n-1;
      while (permutation[temp] > permutation[idx-1]) temp--;
      
      //위치 바꾸기
      swap(permutation, temp, idx-1);

      //뒤에 있게 되는 원소(idx번 인덱스부터) 내림차순(역순) 정렬
      sort(permutation.begin()+idx, permutation.end(), compare);
      break;
    }

    idx--;
  }

  if (idx == 0) cout << -1 << endl;
  else {
    for (auto i : permutation) 
      cout << i << ' ';
    cout << endl;
  }

  return 0;
}