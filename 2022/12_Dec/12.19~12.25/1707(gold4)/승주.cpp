#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    int k, V, E, u, v;
    int w = 0;
    cin >> k;
    while (k--) {
        int flag = 0;
        cin >> V >> E;
        set <int> A;
        set <int> B;
        vector <vector<int>> VV(20001);
        while (E--) {
            cin >> u >> v;
            VV[min(u, v)].push_back(max(u, v));
        }
        bool check = 0;
        int visit[20001] = { 0 };
        w = 0;
        for (int i = 1; i <= V; i++) {
            if (visit[i] == 1) {
                if (i == V) { cout << "XX"; }
                continue;
            }
            if (flag == 1) { break; }
            if (A.find(i) != A.end()) check = 0;
            else if (B.find(i) != B.end()) check = 1;
            else {
                if (w == 0) { A.insert(i); check = 0; }
                else {
                    continue;
                }

            }
            visit[i] = 1;
            for (int j = 0; j < VV[i].size(); j++) {
                int temp = VV[i][j];

                if (check == 0) {
                    if (A.find(temp) != A.end()) { cout << "NO" << endl; flag = 1; break; }
                    B.insert(temp);
                }
                else {
                    if (B.find(temp) != B.end()) { cout << "NO" << endl; flag = 1; break; }
                    A.insert(temp);

                }
            }

            w = 1;
            if (i == V) {
                for (int k = 1; k <= V; k++) {
                    if (visit[k] == 0) {
                        i = k - 1;
                        w = 0;
                        break;
                    }
                    if (k == V) {
                        if (flag == 0) cout << "YES" << endl;
                        break;
                    }
                }

            }

        }
    }
    return 0;
}