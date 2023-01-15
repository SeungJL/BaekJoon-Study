#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
void get_prime();
vector<int> prime_vec;
int t;
bool isprime[10001];
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> t;
    memset(isprime,true,sizeof(isprime));
    get_prime();
    vector<vector<int>> sumprime(prime_vec.size(), vector<int>(prime_vec.size()));
    for(int j = 0; j < prime_vec.size(); j++){
        for(int k = j; k < prime_vec.size(); k++){ 
            int tar = prime_vec[j] + prime_vec[k];
            sumprime[j][k] = tar;
        }
    }
    for(int i = 0; i < t; i ++){
        int n;
        cin >> n;
        int diff = 0x7fffffff;
        int a,b;
        for(int  j = 0; j < prime_vec.size(); j++){
            for(int k = j; k < prime_vec.size(); k++){
                if(prime_vec[k] >= n) break;
                if(sumprime[j][k] == n){
                    int tmpdiff = prime_vec[k] - prime_vec[j];
                    if(tmpdiff < diff){
                        diff = tmpdiff;
                        a = j;
                        b = k;
                    }
                }
            }
        }
        cout << prime_vec[a] << " " << prime_vec[b] << endl;
    }
}
void get_prime(){
    isprime[1] = false;
    int target = 2;
    while(target <= 10000){
        if(isprime[target]){
            int noprime = target;
            int go = target * noprime;
            while(go <= 10000){
                isprime[go] = false;
                go += target;
            }
        }
        target += 1;
    }    
    // isprime[2] = true;
    // isprime[3] = true;
    for(int i = 2; i <= 10000; i++){
        if(isprime[i]){
            prime_vec.push_back(i);
        }
    }

}