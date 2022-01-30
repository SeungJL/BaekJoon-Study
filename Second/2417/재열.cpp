#include <iostream>
#include <cmath>

using namespace std;

int main() {
  unsigned long long n;
  cin >> n;

  unsigned long long result = sqrt(n);
  
  if (pow(result, 2) == n) 
    cout << result << endl;
  else 
    cout << result + 1 << endl;

  return 0;
}
