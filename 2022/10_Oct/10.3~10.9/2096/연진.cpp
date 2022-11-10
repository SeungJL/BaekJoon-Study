#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int N;
  int v[100000][3];
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> v[i][0] >> v[i][1] >> v[i][2];
  }

  int min_score[3] = {
      0,
  };
  int max_score[3] = {
      0,
  };
  int ls, lb, rs, rb;
  int min=1000000, max=0;

  for (int i = 0; i < N; i++)
  {

    // 0
    ls = min_score[0] < min_score[1] ? min_score[0] : min_score[1];
    lb = max_score[0] > max_score[1] ? max_score[0] : max_score[1];
    min_score[0] = v[i][0] + ls;
    max_score[0] = v[i][0] + lb;

    // 2
    rs = min_score[1] < min_score[2] ? min_score[1] : min_score[2];
    rb = max_score[1] > max_score[2] ? max_score[1] : max_score[2];
    min_score[2] = v[i][2] + rs;
    max_score[2] = v[i][2] + rb;

    // 1
    min_score[1] = v[i][1]+(ls<rs ? ls : rs);
    max_score[1] = v[i][1]+(lb>rb ? lb : rb);
  }

  for(int i=0;i<3;i++){
    if(min_score[i]<min) min = min_score[i];
    if(max_score[i]>max) max = max_score[i];
  }
  cout << max << " " << min;

  return 0;
}