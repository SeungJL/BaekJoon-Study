//11723번: 집합
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int result=0;
    int m;
    int x;
    string s;
    cin>>m;
    while(m--){
        cin>>s;
        if(s=="add"){
            cin>>x;
            result= result|(1<<x);
        }else if(s=="remove"){
            cin>>x;
            result=result&~(1<<x);
            
        }else if(s=="check"){
            cin>>x;
            bool check=result&(1<<x);
            if(check==true)
            cout<<1<<"\n";
            else
            cout<<0<<"\n";
        }else if(s=="toggle"){
            cin>>x;
            result=result^(1<<x);
        }else if(s=="all"){
            result=pow(2,21)-1;
        }else{
            result=0;
        }

    }
}