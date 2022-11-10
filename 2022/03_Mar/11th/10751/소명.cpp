//10751번: COW
#include <iostream>
#include <vector>
using namespace std;

int n;
long long c;
long long co;
long long cow;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    string s;
    cin>>s;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='C')
        c++;
       else if(s[i]=='O')
        co+=c;
        else
        cow+=co;
    }
    // cout<<"C: "<<c<<"\n";
    // cout<<"O: "<<co<<"\n";
    // cout<<"W: "<<cow<<"\n";

    cout<<cow<<"\n";
}
// cow->1
// cwow ->1
// ccow ->2
// ccooww ->8
// coowww ->6
// ooccow-> 2
// occowoooocoww -?