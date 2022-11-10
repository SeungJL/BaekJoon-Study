//1406. 에디터
/*
문자열의 길이 N 1<=N<=100,000
명령어의 갯수 1<=M<=500,000
*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;

string s;
int m;
stack<char> st;
stack<char> tmp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s;
    int s_size= s.size();
    for(int i=0; i<s_size; i++){
        st.push(s[i]);
    }
    cin>>m;

    char c;
    while(m--){
        cin>>c;
        if(c=='P'){
            char x;
            cin>>x;
            st.push(x);
        }else if(c=='L'){ //커서 기준, 오른쪽에있는 문자들은 tmp스택에 넣기.
            if(!st.empty()){
                tmp.push(st.top());
                st.pop();
            }
            
        }else if(c=='D'){ //커서 기준 왼쪽에 있는 문자들은 st스택에 넣기.
            if(!tmp.empty()){
                st.push(tmp.top());
                tmp.pop();
            }
        }else{//B
            if(!st.empty()){
                st.pop();
            }
        }
    }

    while(!st.empty()){ //st스택에는 문자가 거꾸로 쌓여있으므로, tmp 스택에 전부 옮기고 top부터 출력
        tmp.push(st.top());
        st.pop();
    }
    while(!tmp.empty()){ //정답 문자열 출력
        cout<<tmp.top();
        tmp.pop();
    }

}