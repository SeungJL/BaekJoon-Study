#include <iostream>
#include <vector>
using namespace std;

int arr[10001]={0};
int sum=0;

void self_number(int n){
    sum=n;
    while(n!=0){
        sum+=n%10;
        n=n/10;
    }
    arr[sum]=1;
}

int main(){
    
    for(int i=1; i<=10000;i++){
        self_number(i);   
    }
    
    for(int i=1;i<=10000;i++){
        if(arr[i]==0) cout << i <<"\n";
    }
    
    return 0;
}
