#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

 
int main(){
  int n;
  int arr[101][101]={0};
  int cnt=0;
  
  cin >> n;

  while(n--){
      int x,y;
      
      cin >> x >> y;
      
      for(int i=x; i<x+10; i++){
          for(int j=y; j<y+10; j++){
              if(!arr[i][j]){ 
                  arr[i][j]=1;
                  cnt++;
              }
          }
      }
  }
    cout << cnt << "\n";
}
