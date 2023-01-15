// 9020] 골드바흐의 추측
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int isPrime(int n) {
  if (n < 2) return 0;
  for(int i=2; i*i<=n; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}

int main() {
  int T, n;
  scanf("%d", &T);
  
  while(T--) {
    scanf("%d", &n);

    for(int i = n/2; i >= 2; i--) {
      if(isPrime(i) && isPrime(n-i)) {
        printf("%d %d\n", i, n-i);
        break;
      }
    }
  }

  return 0;
}
