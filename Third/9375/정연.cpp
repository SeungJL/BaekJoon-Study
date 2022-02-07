#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

 
int main(){
  int n;
  cin >> n;
  
  while(n--){
      int m;
      cin >> m;
      
      unordered_map<string, int> map;
      string s1, s2;
      for(int i=0;i<m;i++){
         cin >> s1 >> s2;
         map[s2]++;
      }
      int ans = 1;
      for(auto i : map){
          ans*=(i.second+1);
      }
      cout << ans-1 <<"\n" ;
        
  }
}
