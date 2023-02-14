#include <iostream>

using namespace std;

int N;
int len[50] = {};

char search(int k, int s, int e) {
    pair<int, int> range;
    range = (k > 0) ? make_pair(s + len[k-1], e - len[k-1]) : make_pair(s, e);
    
    if (range.first <= N && N <= range.second)
        return (N == range.first) ? 'm' : 'o';
    
    if (N < range.first)
        return search(k-1, s, range.first - 1);
    else
        return search(k-1, range.second + 1, e);
    
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int K;
    
    cin >> N;
    len[0] = 3;
    len[1] = 10;
    K = 1;
    while (len[K] < N) {
        K++;
        len[K] = (3 * len[K-1]) - (2 * len[K-2]) + 1;
    }
    cout << search(K, 1, len[K]) << "\n";
}
