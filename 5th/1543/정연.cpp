#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int main()
{
    string str, s;
    getline(cin, str);
    getline(cin, s);
    
    int flag=0, cnt=0;
    
    for(int i=0; i<str.size(); i++){
        flag=0;
        for(int j=0; j<s.size(); j++){
            if(str[i+j]!=s[j]) {
                flag=1;
                break;
            }
        }
        if(flag==0) {
            cnt++;
            i=i+s.size()-1;
        }
        
    }
    cout << cnt;
}
