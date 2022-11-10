#include <iostream>

using namespace std;

int gcd(int a, int b) {
   if (a % b == 0) 
      return b;
   else
      return gcd(b, a % b);
}
int main() {
    
    int T, a, b;
    cin >> T;
    while(T--){
        cin >> a >> b;
        
        cout << a*b/gcd(a,b) << " " << gcd(a,b) <<"\n";
    }
}