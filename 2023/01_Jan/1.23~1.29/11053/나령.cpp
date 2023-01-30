#include <iostream>
#define MAX 1010
using namespace std;
 
int Max(int A, int B) { if (A > B) return A; return B; }
 
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  //freopen("Input.txt", "r", stdin);
  int n;
  int arr[MAX];
  int DP[MAX];
  int answer = 0;
  
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> arr[i];

  
  for (int i = 1; i <= n; i++) {
    DP[i] = 1;
    for (int j = i - 1; j >= 1; j--) {
      if (arr[i] > arr[j]) {
        DP[i] = Max(DP[i], DP[j] + 1);
      }
    }
      answer = Max(DP[i], answer);
  }
 
  cout << answer << "\n";
 
  return 0;
}
