#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100001];
bool go(int k);
int main(){
    cin>>n>>m;
    int start = 0;
    int end = 0;
    for(int i=0;i < n; i++){
        cin>>a[i];
        end += a[i];
        start = max(start, a[i]);
    }
    while(start < end){
        int mid = (start + end) / 2;
        bool res = go(mid);
        if(res){
            end = mid;
        }else{
            start = mid + 1;

        }

    }
    cout<<end<<endl;

}

bool go(int k){
    int balance = 0;
    int left = m;
    for(int i = 0;i < n;i++){
        if(balance < a[i]){
            balance = k;
            left -= 1;
        }
        if(balance - a[i] >= 0){
            balance -= a[i];
        }
    }
    return left >= 0;
}