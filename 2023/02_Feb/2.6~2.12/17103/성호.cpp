#include <iostream>
#include <cmath>
#define MAX_NUMBER 1000001
using namespace std;

//false : 소수 아님 true : 소수
bool isPrimeNumber[MAX_NUMBER]={false};

void getPrimeNumber(){
  for(int i=2;i<=MAX_NUMBER;i++)isPrimeNumber[i]=true;
  for(int i=2;i<=sqrt(MAX_NUMBER);i++)
  {
    if(!isPrimeNumber[i])continue;

    for(int j=i+i;j<=MAX_NUMBER;j+=i)
    {
      isPrimeNumber[j]=false;
    }
  }
}

void solve(int test_case)
{
  int input;
  
  while(test_case--)
  {
    int answer=0;
    cin>>input;
    for(int i=2;i<=input/2;i++)
    {
      if(isPrimeNumber[i]&&isPrimeNumber[input-i])
        answer++;
    }
    cout<<answer<<endl;
  }
}
int main(void)  
{
  cin.tie(NULL);
  cout.tie(NULL);
  cin.sync_with_stdio(false);
  int test_case;cin>>test_case;
  
  getPrimeNumber();
  solve(
    test_case);
}