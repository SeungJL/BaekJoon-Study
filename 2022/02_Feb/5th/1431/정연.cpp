#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;
int compare(string &a, string &b){
    // 크기 비교
    if(a.size() != b.size()) return a.size() < b.size();
    
    // 합 구하고 비교
    int sumA=0, sumB=0;
    for(int i=0; i<a.size(); i++){
        if(a[i]>='0' && a[i]<='9') sumA+=a[i]-'0';
        if(b[i]>='0' && b[i]<='9') sumB+=b[i]-'0';
    }
    if(sumA != sumB) return sumA < sumB;
    
    return a<b;
}
int main()
{
    int n;
    cin >> n;
    
    string s[50];
    for(int i=0; i<n; i++){
        cin >> s[i];
    }
    
    sort(s,s+n,compare);
    
    for(int i=0; i<n; i++){
        cout << s[i] <<"\n";
    }
    
    
}
