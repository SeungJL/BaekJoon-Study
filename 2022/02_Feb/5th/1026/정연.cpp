#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int A[100],B[100];
    for(int i=0; i<n; i++){
        cin >> A[i];
    }
    for(int i=0; i<n; i++){
        cin >> B[i];
    }
    
    sort(A,A+n);
    sort(B,B+n);
    
    int s=0;

    
    for(int i=0; i<n; i++){
       s+=A[i]*B[n-i-1];
    }
    
    cout << s;
    return 0;
}
