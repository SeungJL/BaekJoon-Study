// 5430] AC
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  int T, n;
  string p, arr, tmp;
  
  cin >> T;
  
  while(T--) {
    cin >> p >> n >> arr;

    deque<int> dq;

    for(int i=0; i<arr.length(); i++) {
      if(arr[i]=='[') {
        continue;
      } else if(arr[i] >= '0' && arr[i] <= '9') {
        tmp += arr[i]; // 일단 i를 넣는데 두 자리수면?
      } else if(arr[i] == ',' || arr[i] == ']') {
        if(!tmp.empty()){
          dq.push_back(stoi(tmp));
          tmp.clear(); // tmp 초기화
        }
      }
    }
    
    //-------------------------------------------------//
    
    // 함수 p 연산에 따라 error 판별, 출력 방향 정하기
    bool isReverse = false;
    bool isErr = false;
    
    for(int i=0; i<p.length(); i++) {
      if(p[i] == 'R') isReverse = !isReverse; // isReverse의 반대값을 넣어줌
      else {
        if(dq.empty()) {
          isErr = true;
          cout << "error\n";
          break;
        } else {
          if(isReverse) dq.pop_back();
          else dq.pop_front();
        }
      }
    }
    
    //-------------------------------------------------//
    
    // 정답 출력
    if(!isErr) {
      cout << "[";
      
      if(isReverse) { // 역방향일 때
        while(!dq.empty()) {
          cout << dq.back();
          dq.pop_back();
          if(!dq.empty()) cout << ",";
        }
      } else { // 정방향일 때 (isReverse==false)
        while(!dq.empty()) {
          cout << dq.front();
          dq.pop_front();
          if(!dq.empty()) cout << ",";
        }
      }
      cout << "]\n";
    }

  }

  return 0;
}
