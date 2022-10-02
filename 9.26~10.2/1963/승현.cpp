#include<bits/stdc++.h>
using namespace std;
int n;
string a, b;
bool visited[10000];
void get_cand(queue<pair<string,int>> & q, string cur_a, int cnt);
bool check_prime(int num);
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        memset(visited, false, sizeof(visited));
        int t1, t2;
        cin >> t1 >> t2;
        a = to_string(t1);
        b = to_string(t2);
        memset(visited, false, sizeof(visited));
        queue<pair<string,int>> q;
        q.push(make_pair(a,0));
        visited[stoi(a)] = true;
        bool ok = false;
        while(!q.empty()){
            string cur_a;
            int cnt;
            tie(cur_a, cnt)= q.front();
            // cout<<"cura : "<<cur_a;
            // cout<<"  cnt:"<<cnt<<endl;
            q.pop();
            if(cur_a == b){
                cout << cnt << endl;
                ok = true;
                break;
            }
            get_cand(q, cur_a, cnt);
            
        }
        if(!ok) cout << "Impossible" << endl;
        
    }
}
void get_cand(queue<pair<string,int>> & q, string cur_a, int cnt){
    string original_a = string(cur_a);
    for(int i = 0; i < 4; i++){
        for(int j = 0; j <= 9 ; j++){
            if(i == 0 && j == 0) continue;
            cur_a[i] = j + '0';
            int cur_int = stoi(cur_a);
            if(!visited[cur_int] && check_prime(cur_int)){
                visited[cur_int] = true;
                q.push(make_pair(cur_a, cnt+1));
            }
        }
        cur_a[i] = original_a[i];
    }

}
bool check_prime(int num){
    // cout<<"num"<<num<<endl;
    for(int i = 2; i < num; i++){
        if(num % i == 0) return false;
    }
    return true;
}