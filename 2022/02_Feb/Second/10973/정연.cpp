#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    int n;              
    vector<int> v;     
    
    cin >> n;
    v.resize(n);        
    
    for(int i=0; i<n; i++)
        cin >> v[i];
    
    if(prev_permutation(v.begin(), v.end()))    
    {
        for(int i=0;i<n;i++)
            cout << v[i] << " ";
    }
    else                                        
        cout << "-1";
    

    return 0;
}
