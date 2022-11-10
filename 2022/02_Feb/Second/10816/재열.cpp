#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n;

  unordered_map<long, int> cards;    //key->숫자, value->개수

  //입력
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    if (cards.find(num) == cards.end()) {   //존재하지 않으면
      cards.insert({num,1});
    }
    else {    //존재하면 (1추가)
      cards[num]++;
    }
  }

  //탐색
  cin >> m;
  for (int i = 0; i < m; i++) {
    int num;
    cin >> num;
    if (cards.find(num) == cards.end()) {   //존재하지 않으면
      cout << 0 << ' ';
    }
    else {
      cout << cards[num] << ' ';
    }
  }
  cout << endl;

  return 0;
}