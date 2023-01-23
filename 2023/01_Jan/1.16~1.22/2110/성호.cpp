#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void BS(int n, int c, vector<int> &v)
{
    int right = v[n-1];
    int left = 1;
    int answer = 0;

    while(left<=right)
    {
      int num = 1;
      int mid = (right+left)/2;
      int start = v[0];
      for(int i = 1; i < n; i++)
        if(v[i] - start >= mid) start = v[i],num++;
      if(num >= c) answer = mid, left = mid + 1;
      else  right = mid - 1;
    }

    cout << answer;
}

int main(void)
{
  cin.tie(NULL);
  cin.sync_with_stdio(false);
  int n, c, input;
  cin >> n >> c;
  vector<int> v;
  for (int i = 0; i < n; i++)
  {
    cin >> input;
    v.push_back(input);
  }
  sort(v.begin(),v.end());
  BS(n,c,v);
}