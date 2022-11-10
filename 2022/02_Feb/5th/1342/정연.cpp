#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    
    cin >> s;
    
    int cnt=0, flag=0;
    
    sort(s.begin(), s.end());
    
    do {
        flag=0;
		for(int i=0; i<s.size()-1;i++){
		    if(s[i]==s[i+1]){
		        flag=1;
		        break;
		    }
		}
		if(flag==0) cnt++;
		
	} while (next_permutation(s.begin(), s.end()));
	
	cout << cnt << "\n";
	
}