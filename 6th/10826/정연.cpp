#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
typedef long long ll;
using namespace std;


string add(string a, string b) {
    int sum = 0;
    string res;
    while (!a.empty() || !b.empty() || sum) {
        if (!a.empty()) sum += a.back() - '0', a.pop_back();
        if (!b.empty()) sum += b.back() - '0', b.pop_back();
        res.push_back((sum % 10) + '0');
        sum /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}
int main() {
	
    int n;
    cin >> n;
    string first = "0", second = "1", res = "1";
    for (int i = 1;i < n;i++) {
        res = add(first, second);
        first = second;
        second = res;
    }
    if (n == 0) cout << "0"<<'\n';
    else cout << res<<'\n';
   
	return 0;
}