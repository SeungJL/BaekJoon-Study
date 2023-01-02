#include<iostream>
#include<algorithm>
#include<tuple>
#include<vector>
#include<set>
using namespace std;
int q;
pair<string,multiset<int>> a[100001];
int get_name(string s);
int alen = 0;
int main(){
    cin >> q;
    long ans = 0;
    for(int i = 0; i < q; i++){
        int tok;
        cin >> tok;
        if(tok == 1){
            cin.get();
            string s;
            getline(cin, s,' ');
            int slen;
            cin >> slen;
            int sid = get_name(s);
            if(sid == -1){
                a[alen].first = s;
                for(int j = 0; j < slen; j++){
                    int q;
                    cin >> q;
                    a[alen].second.insert(q);
                } 
                alen += 1;
            }else{
                for(int j = 0; j < slen; j++){
                    int q;
                    cin >> q;
                    a[sid].second.insert(q);
                }
            }
            
            
        }else if(tok == 2){
            cin.get();
            string s;
            getline(cin, s, ' ');
            int sq;
            cin >> sq;
            int sid = get_name(s);
            if(sid == -1) continue;
            
            int c = 0;
            
            while(c < sq){
                auto it = a[sid].second.end();
                if(a[sid].second.begin() == a[sid].second.end()) break;
                it--;
                ans += *it;
                a[sid].second.erase(it);
                // it--;
                c += 1;
            }
            
        
        }else{
            cout << "error!!!!" << endl;
        }
    }
    cout << ans << endl;
}
int get_name(string s){
    for(int i = 0; i < alen; i++){
        if(s == a[i].first){
            return i;
        }
    }
    return -1;
}
