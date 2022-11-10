#include<bits/stdc++.h>
using namespace std;
int n, m;
// vector<int> a[500001];
int root[500001];
bool is_cycle(int,int);
int get_root(int j);
// void change_root(int j, int val);
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    int real_ans = 0;
    //init
    for(int i = 0; i < 500000; i++){
        root[i] = i;
    }
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int s, e;
        cin >> s >> e;
        if(real_ans == 0 && is_cycle(s,e)){
            real_ans = i;
        }
    }
    cout << real_ans << endl;
    return 0;

}
bool is_cycle(int s,int e){
    int sroot = get_root(s);
    int eroot = get_root(e);
    if(sroot == eroot) return true;
    else{
        // change_root(e, sroot);
        root[eroot] = sroot;
        return false;
    }


}
int get_root(int j){
    int s = root[j];
    if(s == j){ // it is root
        return j;
    }else{
        return get_root(s);
    }
}

// void change_root(int j, int val){
//     int s = root[j];
//     root[j] = val;
//     if(s == j); else{
//         change_root(s, val);
//     }
// }