// 2110] 공유기 설치
#include <iostream>
#include <algorithm>
using namespace std;
 
int n,c;
int x[200001];
 
bool ispossible(int interval){
    int current_x = x[0];
    int housenum=1;
    for(int i=1; i<n; i++){
        if(x[i]>=current_x+interval){
            current_x=x[i];
            housenum++;
        }
    }
    if(housenum>=c)
        return true;
    return false;
}
 
int main(void){
    cin>>n>>c;
    int Min,Max=0;
    for(int i=0; i<n; i++){
        cin>>x[i];
        Min = min(Min,x[i]);
        Max = max(Max,x[i]);
    }
    //x 정렬하고
    sort(x,x+n);
    int high = (Max-Min)/(c-1);
    int low=1;
    int answer=0;
    while(low<=high){
        int mid = (high+low)/2;
        if(ispossible(mid)){
            if(answer<mid)
                answer=mid;
            low = mid + 1;
        }
        else{
            high = mid -1;
        }
    }
    cout<<answer;
    
 
}
