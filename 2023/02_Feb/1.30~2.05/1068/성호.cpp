#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[51];
int answer,erase;

void run(int now)
{
  int size = tree[now].size();
  for (auto iter = tree[now].begin(); iter != tree[now].end(); iter++)
  {
    if(*iter==erase)
    {
      size -= 1;
      continue;
    }
    run(*iter);
  }
  if(size==0)
    answer++;
}

int main(void)
{
  int n,input,start;
  cin >> n;
  for (int i = 0; i < n;i++)
  {
    cin >> input;
    if(input!=-1)
      tree[input].push_back(i);
    else
      start = i;
  }
  cin >> erase;
  if(erase==start)
  {
    cout << 0;
    return 0;
  }
  run(start);
  cout << answer;
}