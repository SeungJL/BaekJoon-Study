#include <iostream>
#include <string>
#include <unordered_set> 

using namespace std;

struct Hash {   //해시함수값이 겹치는 것이 없도록 만들음.
  size_t operator()(const pair<char,int>& p) const {
    return p.first * 1000 + p.second;
  }
};

int main() {
  string s;
  cin >> s;

  unordered_set<pair<char,int>, Hash> cards;

  int strIdx = 0;
  while (strIdx < s.length()) {
    string temp = s.substr(strIdx, 3);
    if (cards.find(make_pair<char, int>((char)temp[0], stoi(temp.substr(1,2)))) != cards.end()) {   //이미 있으면
      cout << "GRESKA" << endl;
      return 0;
    }
    cards.insert(make_pair<char, int>((char)temp[0], stoi(temp.substr(1,2))));
    strIdx += 3;
  }

  int pCount=0, kCount=0, hCount=0, tCount=0;

  for (int i = 1; i <= 13; i++) {
    if (cards.find({'P', i}) == cards.end()) pCount++;
    if (cards.find({'K', i}) == cards.end()) kCount++;
    if (cards.find({'H', i}) == cards.end()) hCount++;
    if (cards.find({'T', i}) == cards.end()) tCount++;
  }

  cout << pCount << ' ' << kCount << ' ' << hCount << ' ' << tCount << endl;

  return 0;
}