//1449. 수리공 항승
/*
N:물이 새는 곳 개수, L:테이프의 길이
M,L,물이 새는 위치 <=1,000
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,l;
int cnt[1001];// cnt[i]: i번째까지 고려했을때, 필요한 테이프 갯수 저장

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>l;
    vector<int> v(n,0);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    sort(v.begin(),v.end()); //오름차순 정렬
   
   cnt[0]=1;//테이프 최소 1개 필요
   int start=0; //테이프의 시작지점
   for(int i=1; i<n; i++){
        if(v[i]-v[start]+1>l){ //
            cnt[i]=cnt[i-1]+1;
            start=i; //시작지점 갱신
        }else{
            cnt[i]=cnt[i-1];
        }
   }


   cout<<cnt[n-1]<<"\n";
}