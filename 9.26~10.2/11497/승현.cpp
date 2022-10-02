#include<bits/stdc++.h>
using namespace std;
int t, n;
int start_num;
int get_score();
vector<int> l;
int main(){
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        l.clear();
        for(int j = 0; j < n; j++){
            int temp;
            cin >> temp;
            l.push_back(temp);
            
        }
        cout << get_score() << endl;
    }
}
int get_score(){
    sort(l.begin(), l.end());
    int ans = 0;
    for(int i = 0; i < l.size() - 2 ; i++){
        ans = max(ans, abs(l[i] - l[i+2]));
    }
    return ans;

}