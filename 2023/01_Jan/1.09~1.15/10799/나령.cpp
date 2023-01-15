// 10799] 쇠막대기
#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

char a[100001];
int main(){
  stack<char> st;
  scanf("%s", a);
  int len, cnt=0;
  
  len=strlen(a); //배열의 길이

  for(int i=0; i<len; i++){
    //여는 괄호면 무조건 스택에 push
    if(a[i]=='('){
      st.push('(');
    }

    //닫는 괄호면 pop
    if(a[i]==')' && i>=1){
      st.pop();
      if(a[i-1]=='('){ //레이저이면 스택 사이즈만큼 더해줌
        cnt+=st.size();
      }else{ //파이프의 끝이면 닫혀서 잘려진 갯수 더해줌
        cnt++;
      }
    }
    
    if(a[i]==0) break;
  }

  printf("%d", cnt);
}