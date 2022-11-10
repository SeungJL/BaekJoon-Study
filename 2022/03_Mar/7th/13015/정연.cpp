#include<iostream>
#include<queue>
#include<vector>
#include<string>
using namespace std;
 

 
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < 2 * n - 1; i++) { 
        // 맨위 맨 아래 
        if (i == 0 || i == 2 * n - 2) { 
            for (int j = 0; j < n; j++) { 
                cout << "*"; 
                
            } 
            for (int j = 0; j < 2 * n - 3; j++) { 
                cout << " "; 
                
            } 
            for (int j = 0; j < n; j++) { 
                cout << "*"; 
                
            } 
            cout << "\n"; 
            continue; 
            
        } 
        // 가운데 
        if (i == n - 1) { 
            for (int j = 0; j < n - 1;j++) { 
                cout << " "; 
                
            } 
            cout << "*"; 
            for (int j = 0; j < n - 2; j++) { 
                cout << " "; 
                
            } 
            cout << "*"; 
            for (int j = 0; j < n - 2; j++) { 
                cout << " "; 
                
            } 
            cout << "*\n"; 
            continue; 
            
        } 
        // 나머지 
        for (int j = 0; j < (n - 1) - abs(n - 1 - i); j++) { 
            cout << " "; } cout << "*"; 
            for (int j = 0; j < n - 2; j++) { 
                cout << " "; 
                
            } 
            cout << "*"; 
            for (int j = 0; j < 2 * abs((n - 1) - i) - 1; j++) { 
                cout << " "; 
                
            } 
            cout << "*"; 
            for (int j = 0; j < n - 2; j++) { 
                cout << " "; 
                
            } 
            cout << "*\n"; 
        
    }

}
