#include <iostream>

using namespace std;

int main() {
  int n, r, c;
  cin >> n >> r >> c;

  bool matrix[n][n];
  r--;
  c--;

  matrix[r][c] = true;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if ((i%2 == r%2 && j%2 == c%2) || (i%2 != r%2 && j%2 != c%2)) {
        matrix[i][j] = true;
        cout << 'v';
      }
      else {
        matrix[i][j] = false;
        cout << '.';
      }  
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}