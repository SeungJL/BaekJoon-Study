#include <iostream>

using namespace std;

int main() {
    
    int arr[10], sum=0;
    for(int i=0; i<10;i++){
        cin >> arr[i];
    }
    int i;
    for(i=0; i<10;i++){
        sum+=arr[i];
        if(sum >=100) {
            break;
        }
    }
    int a = sum-100;
    int b = 100 - (sum-arr[i]);
    
    if(a<=b) cout << sum;
    else cout << sum-arr[i];
       
}