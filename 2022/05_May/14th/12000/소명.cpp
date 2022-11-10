//12000번: Circular Barn (Bronze)
/*
풀이
각 방에 있는 소의 마리 수를 cow배열에 입력받는다.
1번방부터~n번방까지 각 방의 문이 잠금해제 되었을때, 소들이 움직이는 총 거리를 구한다.
예를들어, 2번방의 외부문을 열었을때의 소들이 움직이는 총합을 구한다고 가정하면
2번방의 소들이 움직이는 거리 + 3번방의 소들이 움직이는 거리 + 4, 5, 1번방의 소들의 움직이는 거리를 sum에 저장한다.
이때, i번 방에있는 소들이 움직여야하는 거리의 총합은 cow[i]*weight이다. 
weight는 현재 방번호가 기준이 되는 방 번호에서 1씩 커질수록 가중치도 그만큼 증가한다.
최소 거리를 anwer에 기록한다.

*/
#include <iostream>

using namespace std;

#define MAX 2147483647

int cow[1001];
int n;
int sum,weight; //weight: 소가 움직이는 거리의 가중치
int answer=MAX; //int최대값으로 초기화

int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>cow[i];
    }
    
    for(int i=1; i<=n; i++){
        int cnt=n;
        weight=0;
        sum=0;
        while(cnt--){ //아래 과정을 반복하는 횟수는 방의 갯수인 n번이다.
            sum+=(weight*cow[i]); //i번째 방부터 오름차순으로 계산한다.

            if(i==n){ //마지막 방에 도달하면, 그때를 계산하고, 가중치를 올리고, 1번방으로 돌아간다.
                i=1;
                weight++;
                continue;
            }
            i++; weight++;
         
        }
        if(answer>sum) //최솟값 구하기
            answer=sum;
    
    } 

    cout<<answer<<'\n';
}