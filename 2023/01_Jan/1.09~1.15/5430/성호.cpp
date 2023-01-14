#include <iostream>
#include <string>
#include <deque>
using namespace std;

deque<int> dq;

void Input(string str){
  string s;
  for (int i = 0; i < str.length();i++){
    if (isdigit(str[i]))
    {
      s += str[i];
      }
      else
      {
        if(!s.empty())
        {
          dq.push_back(stoi(s));
          s="";
        }
      }
  }
}

int mainFunc(string p){
  int isFront = true;
  for (int i = 0; i < p.size(); i++)
  {
    if(p[i]=='R')
    {
      isFront=!isFront;
    }
    else{
      if(dq.empty()){
        cout << "error" << endl;
        return 2;
      }
      else{
        if(isFront)
          dq.pop_front();
        else
          dq.pop_back();
      }
    }
  }
  return isFront;
}

void Output(int isFront)
{
  cout << "[";
  if(isFront){
    while(!dq.empty()){
      cout << dq.front();
      dq.pop_front();
      if (!dq.empty())
        cout << ",";
    }
  }
  else{
    while(!dq.empty()){
      cout << dq.back();
      dq.pop_back();
      if (!dq.empty())
        cout << ",";
    }
  }
  cout << "]" << endl;
}
int main(void)
{
  int T,n;
  cin >> T;
  while(T--){
    string p,str;
    
    cin >> p >> n >> str;

    Input(str);
    int isFront =mainFunc(p);
    if(isFront!=2)Output(isFront);
  }
}