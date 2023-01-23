#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int n, c;
vector<long long> a;
bool possible(long long dist);
int main(){
    cin >> n >> c;
    for(int i = 0; i < n ; i++){
        int tmp ;
        cin >> tmp;
        a.push_back(tmp);
    }
    sort(a.begin(), a.end());
    
    long long low = 1;
    long long high = a[a.size() - 1] - a[0];
    long long ans = 0;
    while(low <= high){
        long long mid = (low + high) / 2;
        // cout << "mid" << mid << endl;
        if(possible(mid)){
            ans = max(ans, mid);
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    cout << ans << endl;


}
/*
이 부분이 가장 중요
*/
bool possible(long long dist){
    // cout << "dist" << dist << endl;
    int router = a[0];
    int cnt = 1;
    for(int k = 0; k < n; k++){
        if(a[k] - router >= dist){
            cnt += 1;
            router = a[k];
        }
        if(cnt >= c) return true;
    }
    
    return false;
}
