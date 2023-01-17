#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int bag[300001] = { 0, };
pair<int, int> jew[300001];
priority_queue<int> pq;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k;
    cin >> n >> k;

    for(int i=0; i<n; i++) {
        int m, v;
        cin >> m >> v;
        jew[i].first = m;
        jew[i].second = v;
    }

    for(int i=0; i<k; i++){
        int c;
        cin >> c;
        bag[i] = c;
    }
    sort(bag, bag+k); // 가방 오름차순 정렬
    sort(jew, jew + n); // 보석 무게 오름차순으로 정렬 ( 무게 같으면 가격 오름차순 )

    long long sum = 0;
    int idx = 0;
    for(int i=0; i<k; i++) { 

        // 가방 무게보다 가벼운 보석들의 가격을 pq에 담음
        while(idx < n && jew[idx].first <= bag[i]) {
            pq.push(jew[idx].second);
            idx++;
        }

        // 가장 가격이 높은 보석의 가격을 sum에 합치면서 pq에서 pop
        // 다음 가방에도 pq에서 가장 가격이 높은게 들어감
        // 무게가 가방보다 낮은것들만 위에서 걸러서 넣었기 때문에 가능
        if(!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
    }
    cout << sum;
}