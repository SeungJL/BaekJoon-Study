#include <iostream>
#include <stack>
#include <vector>
using namespace std;

typedef struct bar{
  int from;
  int to;
} Bar;

vector<Bar> bars;
vector<int> lasers;
stack<int> s;

void findBarsAndlasers(string input){
  for (int i = 0; i < input.size(); i++)
  {
    if(input[i]=='(')
      s.push(i);
    else{
      int from = s.top();
      s.pop();
      
      if(i-1==from)
        lasers.push_back(i);
      else{
        bars.push_back({from, i});
      }
    }
  }
}

int main(void)
{
  string input;
  cin >> input;
  findBarsAndlasers(input);

  int answer = bars.size();
  for (auto i = 0; i < bars.size();i++)
  {
    for (auto j = 0; j < lasers.size();j++)
    {
      if(lasers[j]>bars[i].from&&lasers[j]<bars[i].to)
        answer++;
    }
  }
  cout << answer;
}