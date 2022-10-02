#include<bits/stdc++.h>
using namespace std;
vector<int> a;
int n;
int get_ans();
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    
    sort(a.begin(), a.end());
    int real_ans = 0;
    do{
        real_ans = max(real_ans, get_ans());
    }while(next_permutation(a.begin(), a.end()));
    
    cout << real_ans << endl;
}

int get_ans(){
    int ans = 0;
    for(int i = 0; i < n-1; i++){
        ans += abs(a[i] - a[i+1]);
    }
    return ans;
}

//10.02 승주
