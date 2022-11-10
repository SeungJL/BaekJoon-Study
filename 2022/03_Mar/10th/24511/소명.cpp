//24511번: queuestack
#include <iostream>
#include <deque>

using namespace std;

deque<int> dq;
int n,m;
bool flag[100001];
//0:queue, 1:stack

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>flag[i];
    }
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        if(flag[i]==0)
        dq.push_back(x);
    }
    cin>>m;
    for(int i=0; i<m; i++){
        int y;
        cin>>y;
        dq.push_front(y);
        cout<<dq.back()<<" ";
        dq.pop_back();
        
    }
    //전부 stack일 경우, dq에 미리 넣는 과정없이  새 dq에 push_front, pop_back과정 반복하면 됨.

}
