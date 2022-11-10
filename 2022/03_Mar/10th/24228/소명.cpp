//24228번: 젓가락
#include <iostream>
using namespace std;

long long func(long long n,long long r){
    // if(n==1)
    // return 2*r;

    long long result=0;
    result = r*2+(n-1);
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
     long long n,r;
    cin>>n>>r;
    cout<<func(n,r)<<"\n";

}