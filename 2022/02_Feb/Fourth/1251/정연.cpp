#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main()
{
    
    string str;
    
    cin >> str;
    
    string min = "{";
    
    for(int i=0; i<str.size()-2; i++){
        for(int j=i+1; j<str.size()-1; j++){
            string result ="";
            for(int s=i; s>=0; s--)
                result += str[s];
            for(int s=j; s>i; s--)
                result += str[s];
            for(int s=str.size()-1; s>j; s--)
                result += str[s];

            
            if(result < min) min = result;
        }
    }

    cout << min << "\n";
    
    return 0;
}
