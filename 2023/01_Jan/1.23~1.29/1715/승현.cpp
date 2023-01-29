#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
int n;
multiset<long long> a;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        a.insert(tmp);
    }
    if(n == 1){
        if(*a.begin() == 1) cout << 0 << endl;
        else cout << *a.begin() << endl;
        return 0;
    }
    long long ans = 0;
    while(a.size() != 1){
        long long tar = * a.begin() + * (++a.begin());
        ans += tar;
        // cout << "tartar" << tar<<endl;
        a.erase(a.begin());
        a.erase(a.begin());
        a.insert(tar);
    }
    cout << ans << endl;
}