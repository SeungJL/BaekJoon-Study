#include <iostream>

using namespace std;

int isPrime(int n){

    for(int i=2; i<n; i++){
        if(n%i==0) return 0;
    }
    
    return 1;
}

int main(){
  ios_base :: sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL); 
  
  int n;
  cin >> n;
  
  while(n--){
      int x;
      cin >> x;
      for(int i=x/2; i>0; i--){
          if(isPrime(i) && isPrime(x-i)){
             int m = min(i,x-i);
             cout << m<< " " << x-m<<"\n";
             break;
          }
      }
      
     
  }
}
