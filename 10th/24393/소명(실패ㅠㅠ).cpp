//24393번 : 조커 찾기
#include <iostream>
using namespace std;

int n;
int jo;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    jo = 1; //조커의 인덱스
    bool joker=false;//조커가 오른쪽이면 true, 왼쪽이면 false
    //조커는 처음에 왼쪽이므로 false로 초기화
    bool flag=true; //가져오는 덱이 오른쪽 덱이면 true, 왼쪽 덱이면 false
    //오른쪽 덱부터 가져오니까 flag는 true로 초기화

    cin>>n;
    for(int i=0; i<n; i++){
        int a;
        int sum=0;
           if(jo<=13){ //조커 인덱스<=13이면 왼쪽으로감
            joker=false;
            jo=jo;
            cout<<"한텀끝나고 조커 위치 : "<<jo<<endl;
        }else{// 조커 인덱스>14면 오른쪽으로감
            joker=true;
            jo-=13;
             cout<<"한텀끝나고 조커 위치 : "<<jo<<endl;
        }
        while(cin>>a){
            if(flag==joker){ //조커방향과 현재 가져오는덱의 방향이 같은경우
                if(a<jo){
                    sum+=a;
                   cout<<"sum = "<<sum <<endl;
                }else{
                    jo=sum+jo;
                   cout<<"jo= "<<jo<<endl;
                    sum+=a;
                   cout<<"sum= "<<sum<<endl;
                }
                flag=!flag;
            }else{ //방향 다른 경우
                sum+=a;
               cout<<"sum= "<<sum<<endl;
                flag=!flag;
            }
            cout<<"a하나 입력 끝: "<<a<<",  jo= "<<jo <<endl;
        
        }
     
    

        if(jo<=13){ //조커가 왼족에 있는경우
        }
    }
    cout << jo <<"\n";
}
