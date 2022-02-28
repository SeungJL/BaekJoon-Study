#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    
    vector<int> v(8), x(8);
    for(int i=0; i<8; i++){
        cin >> v[i];
        x[i]=v[i];
    }

    sort(v.rbegin(),v.rend());
    
    int sum=0;
    for(int i=0; i<5; i++){
        sum+=v[i];
    }
    cout << sum << "\n";
    
    for(int j=0; j<8;j++){
        for(int i=0; i<5; i++){
            if(v[i]==x[j]) cout << j+1 <<" ";
        }
    }
}