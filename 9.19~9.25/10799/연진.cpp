#include <iostream>
#include <vector>
using namespace std;

int main()
{
  string str;
  cin >> str;

  int count = 0; // 잘려진 조각 개수
  vector<int> sticks;

  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] == '(' && str[i + 1] == ')') // 레이저. 전체 stick 스택값을 +1.
    {
      if (!sticks.empty())
        sticks.back()++; // 제일 위 막대가 잘릴 횟수만 알면 그밑에꺼에 더해주면 됨
      i++;
    }
    else if (str[i] == '(') // 스틱 시작
      sticks.push_back(1);
    else // 스틱 끝
    {
      int temp = sticks.back();
      count += temp;
      sticks.pop_back();
      if (!sticks.empty())
        sticks.back() += temp - 1;
    }
  }
  cout << count;

  return 0;
}