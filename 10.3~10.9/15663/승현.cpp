#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a;
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    sort(a.begin(), a.end());
    
    vector<int> last_one(m, -1);  
    do{
        vector<int> new_one(m);
        for(int i = 0; i < m; i++){
            new_one[i] = a[i];
        }

        if(new_one != last_one){
            for(auto it : new_one){
                cout << it << " ";
            }
            cout << endl;
            last_one = new_one;
        }
    
    }while(next_permutation(a.begin(), a.end()));
}