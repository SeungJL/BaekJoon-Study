#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
int n, m;
vector<tuple<long,int,int>> a;
vector<long> V;
int treeparent[100001];
int getroot(int x);
// krustal algorithm
int main(){
    // cin.tie(0);
    // cout.tie(0);
    // ios::sync_with_stdio(false);
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m ; i++){
        int s, e;
        long w;
        // cin >> s >> e >> w;
        scanf("%d %d %ld", &s, &e , &w);
        a.push_back(make_tuple(w,s,e));
    }
    sort(a.begin(), a.end());
    for(int i = 1; i <= n; i++){
        treeparent[i] = i;
    }

    // visited[1] = true;
    // long total_cost = get<0>(a[0]);
    // int visit_size = 1;
    // int cur_idx = 1;
    for(int i = 0; i < a.size(); i++){
        long nextw;
        int nexts, nexte;
        tie(nextw, nexts, nexte) = a[i];
        int eroot = getroot(nexte);
        int sroot = getroot(nexts);
        if(eroot != sroot){
            treeparent[eroot] = sroot;
            V.push_back(nextw);

        }
    }
    long ans = 0;
    for(int i = 0; i < V.size() - 1; i++){
        ans += V[i];
    }
    printf("%ld\n", ans);

   

}

 

int getroot(int x){
    if(treeparent[x] == x) return x;
    else return treeparent[x] = getroot(treeparent[x]);
}

