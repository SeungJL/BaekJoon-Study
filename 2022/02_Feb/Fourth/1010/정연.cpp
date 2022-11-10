#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    
    int n,m;
    for(int i=0; i<t; i++){
        cin >> n >> m;
        long long res =1;
        if(n > m/2) n= (m-n);
        for(int j=0; j<n; j++){
            res*=m-j;
        }
        
        for(int k=0; k<n; k++){
            res/=(k+1);
        }
        
        cout << res <<"\n";
    }
    

    return 0;
}
