//1654번: 랜선 자르기

/*

이미 있는 랜선 K개 :
1<=k<=10,000

필요한 랜선 N개:
1 <= N <= 1,000,000

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,k;
vector<int> v;
int answer;

void func(){
    // 랜선 길이의 최댓값은 v의 최댓값
    long long start=1;
    long long end=v[k-1];

    //여기 주의 . start==end==mid일때 mid가 최댓값으로 답일수도 있음.
    while(start<=end){
        long long mid=(start+end)/2;
        int sum=0;
        //mid가 현재 자르려는 길이
        for(int i=0; i<k; i++){
            sum+=v[i]/mid;
        }
      
        if(sum>=n){
            if(answer<mid)
            answer=mid;

            start=mid+1;
        }else{
            end=mid-1;
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>k>>n;
    for(int i=0; i<k; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());

    func();
    cout<<answer<<"\n";

}