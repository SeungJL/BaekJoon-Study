#include <iostream>
#include <vector>

using namespace std;

#define MAX 1000000

int primes[78500], cnt = 0;
vector<bool> is_prime(MAX+1, true);

void get_primes() {
    is_prime[0] = false; is_prime[1] = false;
    for (int i=2; i <= MAX; i++) {
        if (!is_prime[i]) continue;
        primes[cnt++] = i;
        for (int j = i+i; j <= MAX; j+=i)
            is_prime[j] = false;
    }    
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen("input.txt", "rt", stdin);
    
    int tc, num, answer; 
    get_primes();
    
    cin >> tc;
    while (tc--) {
        cin >> num;
        answer = 0;
        
        for (int i=0; i<cnt; i++) {
            if (primes[i] * 2 > num) break;
            if (is_prime[num - primes[i]]) 
                answer++;
        }
        cout << answer << "\n";
    }
}
