#include <iostream>
#include <algorithm>
using namespace std;

int cake[1001]={0};

int main()
{
    int l, n;
    
    cin >> l >> n;
    int p, k;
    int cnt,index,rindex;
    int max=0, rmax=0;
    for(int i=1; i<=n; i++){
        cin >> p >> k;
        
        if(k-p>max){
            max = k-p;
            index = i;
        }
        
        cnt=0;
        for(int j=p;j<=k;j++){
            if(cake[j]!=0) continue;
            if(cake[j]==0){
                cake[j]=i;
                cnt++;
            }           
        }
        
        if(cnt > rmax){
            rmax=cnt;
            rindex=i;
        }
    }

    cout << index <<"\n" << rindex;
    
    return 0;
}