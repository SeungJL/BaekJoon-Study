#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;

int n,k;
vector <string> card;
set <string> cardSet;
vector <string> tmp;
int ck[11];

void dfs(int depth){
    if(depth == k){
        string c;
        for(auto t : tmp) c += t;
        cardSet.insert(c);
        return;
    }
    for(int i = 0; i < n; i++){
        if(ck[i]) continue;
        ck[i] = 1;
        tmp.push_back(card[i]);
        dfs(depth + 1);
        tmp.pop_back();
        ck[i] = 0;
    }
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        card.push_back(s);
    }
    dfs(0);
    cout << cardSet.size() << '\n';
}