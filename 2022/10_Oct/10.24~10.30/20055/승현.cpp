#include<bits/stdc++.h>
using namespace std;
int a[201];
bool isrobot[201];
int n,k;
bool device_check();
void device_spin();
void canmove();
int main(){
    cin >> n >> k;
    for(int i = 1; i <= 2*n; i++){
        cin >> a[i];
    }
    int round = 1;
    while(1){
        device_spin();
        canmove();
        if(a[1] > 0){
            isrobot[1] = true;
            a[1] -= 1;
        }
        // cout<< "========="<<endl;
        // cout<< "round "<< round << endl;
        // for(int i =1; i<=2*n;i++){
        //     cout << a[i]<<" ";
        // }
        
        // cout<<endl;
        // for(int i = 1; i <= n;i++){
        //     cout << isrobot[i] <<" ";
        // }
        // cout<<endl;
        // if(round == 10) break;
        if(device_check()) round += 1;
        else break;
    }
    cout << round << endl;
}

bool device_check(){
    int ea = 0;
    for(int i = 1; i <= 2*n; i++){
        if(a[i] == 0){
            ea += 1;
        }
    }

    if(ea < k){
        return true;
    }else return false;
}

void device_spin(){
    int tmp = a[2*n];
    int tmp2 = a[1];
    a[2*n] = a[2*n - 1];
    a[1] = tmp;
    tmp = tmp2;
    for(int i = 1; i < 2*n - 1 ; i++){
        tmp2 = a[i+1];
        a[i+1] = tmp;
        tmp = tmp2;
    }
    if(isrobot[n]){
        // a[n+1] -= 1; //내릴때 내구도가 1 감소된다?
        isrobot[n] = false;
    }
    for(int i = n-1; i >= 1 ; i--){
        if(isrobot[i]){
            isrobot[i+1] = true;
            isrobot[i] = false;  
        }
    }

}
void canmove(){
    if(isrobot[n]) isrobot[n] = false; // move할 수 있으면 떨어진다.
    for(int i = n-1; i >= 1; i--){
        if(isrobot[i] && !isrobot[i+1] && (a[i+1] > 0)){
            isrobot[i+1] = true;
            isrobot[i] = false;
            a[i+1] -= 1;
        }
    }

