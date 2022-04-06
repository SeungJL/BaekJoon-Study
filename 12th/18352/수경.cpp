#include <bits/stdc++.h>

using namespace std;

vector <pair<int, int>> city;
queue <pair<int, int>> dist;
vector<int> ans;


bool visited[300001];

void BFS(int K, int X) {

    dist.push(make_pair(X, 0));
    visited[X] = true;

    while (!dist.empty()) {
        int index = dist.front().first;
        int index_dist = dist.front().second;
        dist.pop();
        if (index_dist == K) {
            ans.push_back(index);
            continue;
        }

        for (int i = 0; i < city.size(); i++) {
            if (city[i].first == index && visited[city[i].second] == false) {
                dist.push(make_pair(city[i].second, index_dist + 1));
                visited[city[i].second] = true;
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K, X;
    cin >> N >> M >> K >> X;
    for (int i = 0; i < M; i++) {
        int origin, destination;
        cin >> origin >> destination;
        city.push_back(make_pair(origin, destination));

    }

    BFS(K, X);

    if (ans.empty()) cout << -1 << "\n";
    else {
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++) cout << ans[i] << "\n";
    }

    return 0;
}

/*
 *
7 6 2 1
1 2
1 3
2 4
2 5
3 6
3 7
 */