#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;


int main()
{
    string s;
    vector<int> card[4];
    cin >> s ;
    
    int index;
    for(int i=0; i<s.size() ; i+=3){
        int x = (s[i + 1] - '0')*10 + (s[i + 2] - '0');
		
        switch(s[i]){
            case 'P':
                index=0;
                break;
            case 'K':
                index=1;
                break;
            case 'H':
                index=2;
                break;
            case 'T':
                index=3;
                break;
        }
        
        if(find(card[index].begin(), card[index].end(), x)==card[index].end()){
			card[index].push_back(x);
		}
		else{
		    cout << "GRESKA" << endl;
			return 0;
		}
		
    }
    
    for(int i=0; i<4;i++){
        cout << 13 - card[i].size() << " ";
    }
   
    

    return 0;
}
