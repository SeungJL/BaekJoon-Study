#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


int main()
{
    int n; 
    cin >> n;
    
    vector<int> v;
    v.resize(n);
    
    for(int i=0 ; i<n ; i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    int flag=0;
    
    for(int i=n-1; i>1; i--){
         if(v[i] < v[i-1]+v[i-2]){
            cout << v[i]+v[i-1]+v[i-2] <<"\n";
            flag = 1;
            break;
         }
    }
    if(flag ==0) cout << -1 <<"\n";

    return 0;
}
