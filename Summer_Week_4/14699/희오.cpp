// BOJ 14699 관악산 등산

#include <iostream>
#include <vector>
#include <algorithm> // sort 

using namespace std;

struct Shelter {
    int num, height;
    Shelter(int _n, int _h) : num(_n), height(_h) {};
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt", "rt", stdin);

    int N, M;
    vector<Shelter> V;
    vector<int> E[5000];
    
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        int h;
        cin >> h;
        V.push_back(Shelter(i, h));
    }
    for (int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        (V[a].height > V[b].height) ? E[b].push_back(a) : E[a].push_back(b);
    }

    sort(V.begin(), V.end(), 
        [](Shelter a, Shelter b) -> bool {return (a.height > b.height);});

    vector<int> res(N, 0);
    for (auto v : V) {
        int max = 0;
        for (auto e : E[v.num])
            if (max < res[e]) max = res[e];
        res[v.num] = max + 1;
    }

    for (auto e : res)
        cout << e << "\n";
}