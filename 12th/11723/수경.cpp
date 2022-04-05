#include <bits/stdc++.h>

using namespace std;

set<int> S;
set<int> all = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    while(N--){
        string order;
        cin >> order;
        if(order == "add"){
            int tmp;
            cin >> tmp;
            S.insert(tmp);
        }
        else if(order == "remove"){
            int tmp;
            cin >> tmp;
            if(S.find(tmp) == S.end()) continue;
            S.erase(tmp);
        }
        else if(order == "check"){
            int tmp;
            cin >> tmp;
            if(S.find(tmp) == S.end()) cout << 0 << "\n";
            else cout << 1 << "\n";
        }
        else if(order == "toggle"){
            int tmp;
            cin >> tmp;
            if(S.find(tmp) == S.end()) {
                S.insert(tmp);
            }
            else {
                S.erase(tmp);

            }
        }
        else if(order == "all"){
            S = all;
        }
        else if(order == "empty") S.clear();

    }
    return 0;
}