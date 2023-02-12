#include <iostream>
#include <queue>
using namespace std;

int main(void)  
{
  int numOfCard, numOfSum,input;
  cin >> numOfCard >> numOfSum;
  priority_queue<long long, vector<long long>, greater<long long>> cards;
  while(numOfCard--)
    cin >> input, cards.push(input);

  long long minNum1, minNum2;
  for (int i = 0; i < numOfSum;i++)
  {
    minNum1 = cards.top();
    cards.pop();
    minNum2 = cards.top();
    cards.pop();
    minNum1 = minNum1 + minNum2;
    minNum2 = minNum1;

    cards.push(minNum1);cards.push(minNum2);
  }
  long long  answer = 0;
  while (!cards.empty())
    answer += cards.top(), cards.pop();

  cout << answer;
}