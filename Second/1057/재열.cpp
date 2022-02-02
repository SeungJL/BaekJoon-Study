#include <iostream>
#include <cmath>

using namespace std;

int nextIndex(int prevIndex) {    //다음 라운드에서의 인덱스를 반환하는 함수
  return static_cast<int>(ceil(prevIndex / 2.0));  
}

bool findIfMeet(int a, int b) {   //a인덱스와 b인덱스가 대결하는지 판단하는 함수
  if (b == (a+1) && (a%2 != 0))
    return true;
  if (a == (b+1) && (b%2 != 0)) 
    return true;
  return false;
}

int main() {
  int n, jiminIndex, hansuIndex;  
  int count = 1;

  cin >> n >> jiminIndex >> hansuIndex;

  while (!findIfMeet(jiminIndex, hansuIndex)) {   //대결하면 탈출
    count++;
    jiminIndex = nextIndex(jiminIndex);
    hansuIndex = nextIndex(hansuIndex);
  }

  cout << count << endl;

  return 0;
}