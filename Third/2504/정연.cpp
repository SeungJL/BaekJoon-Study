#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

int main(){
  ios_base :: sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL); 
  
  stack<char> s, oper;
  stack<int> num;
  string str;
  
  cin >> str ;
  
  for(int i=0; i<str.size(); i++){
      switch(str[i]){
          case '(':
            s.push(str[i]);
            num.push(2);
            break;
          case ')':
            s.pop();
            oper.push('+');
            break;
          case '[':
            s.push(str[i]);
            num.push(3);
            break;
          case ']':
            s.pop();
            oper.push('*');
            break;
          
      }
  }
  

  int a, b;
  char o;
  while(!num.empty()){
      a = num.top(); num.pop();
      b = num.top(); num.pop();
      o = oper.top(); oper.pop();
      if(o =='*'){
          num.push(a*b);
      }
      if(o =='+'){
          num.push(a+b);
      }
      cout << a << " " << b << "\n";
      
  }
  
  return 0;
   
}
