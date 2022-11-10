#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;


int main()
{
    int T;
    cin >> T;

    for(int j=0 ; j<T ; j++){
        int n;
        cin >> n;
        vector<int> v(n);
        
        for(int i=0; i<n;i++){
            cin >>v[i];
        }
        ll result =0;
        int max_value = -1;
        
        for(int i=n-1; i>=0 ; i--){
            max_value = max(max_value, v[i]);
            result += max_value - v[i];
        }
        
        cout << result << "\n";
    }
}