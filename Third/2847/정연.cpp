#include <iostream>
#include <algorithm>

using namespace std;
 
int main(){
   int n, score[101]={0};
   
   cin >> n ; 
   
   for(int i=0; i<n; i++){
       cin >> score[i];
   }
   int cnt = 0;
   
   for(int i=n-1; i>0; i--){
       while(score[i] <= score[i-1]){
           cnt++;
           score[i-1]--;
       }
     
   }
   
   cout << cnt << "\n";
}
