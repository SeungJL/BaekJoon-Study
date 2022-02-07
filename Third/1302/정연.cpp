#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
 

int main() {
    int n;
    
    cin >> n;
    
    string s;

    map<string, int> map;
     
    for(int i=0; i<n ; i++){
        cin >> s;
        map[s]++;
    }
  
  
    int result=0;
    
  
    for(auto i = map.begin(); i!=map.end();i++){
       result = max(result, i->second);
    }
    for(auto i = map.begin(); i!=map.end();i++){
        if(result == i->second){
            cout << i->first;
            return 0;
        }
    }

}
