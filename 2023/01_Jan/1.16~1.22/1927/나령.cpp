// 1927] 최소 힙 (값이 작을수록 우선순위가 높은 우선순위 큐)
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  freopen("input.txt", "rt", stdin);
  
  int n, x;
  priority_queue<int, vector<int>, greater<int>> q;
  
	cin >> n; 
  
  for(int i=0; i<n; i++) {
    cin >> x;
    
    if (x==0) {
      if(q.empty()) {
        cout<<"0\n";
      } else {
        cout<<q.top()<<"\n";
        q.pop();
      }
    } else {
      q.push(x);
    }
  }
  return 0;
}