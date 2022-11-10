
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Country {
public:
  int index;
  int gold;
  int silver;
  int bronze;

  Country(int i, int g, int s, int b) {
    this->index = i;
    this->gold = g;
    this->silver = s;
    this->bronze = b;
  }

  bool operator==(const Country& c) {
    if (this->index == c.index) return true;
    else return false;
  }
};

bool compare(Country& c1, Country& c2) {
  if (c1.gold > c2.gold) return true;
  else if (c1.gold < c2.gold) return false;
  else {
    if (c1.silver > c2.silver) return true;
    else if (c1.silver < c2.silver) return false;
    else {
      if (c1.bronze > c2.bronze) return true;
      else return false;
    }
  }
}

int main() {
  int n;
  int k;
  cin >> n >> k;

  vector<Country> countries;

  for (int i = 0; i < n; i++) {
    int index, gold, silver, bronze;
    cin >> index >> gold >> silver >> bronze;
    countries.push_back(Country(index, gold, silver, bronze));
  }

  sort(countries.begin(), countries.end(), compare);

  auto iter = find(countries.begin(), countries.end(), Country(k,0,0,0));
  int targetIndex = distance(countries.begin(), iter);

  //앞 인덱스의 나라와 동점인지 체크 (동점 아닌 나라를 만날때까지 targetIndex를 감소시킴)
  while (true) {
    if (!(countries[targetIndex].gold == countries[targetIndex-1].gold
          && countries[targetIndex].silver == countries[targetIndex-1].silver
          && countries[targetIndex].bronze == countries[targetIndex-1].bronze
        )) {
      break;
    }
    targetIndex--;
  }

  //등수는 1로 시작하므로 1 더해서 출력해야 함.
  cout << targetIndex + 1 << endl;

  return 0;
}