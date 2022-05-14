//16918번: 봄버맨
/*

R,C,N
( 1<= R,C,N <= 200)
빈칸: .
폭탄: 0

*/
#include <iostream>
using namespace std;
int r,c,n;
char arr[200][200]; //격자판 배열
char save[200][200];//arr배열 저장해놓는 용도
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

void printArr(){ //배열 출력 함수
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<arr[i][j];
        }
        cout<<"\n";
    }
}

void install(){ //짝수초에 모든칸에 폭탄이 설치되는 경우: 모든칸을 0으로 채워준다.
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            arr[i][j]='O';
        }
    }

}

void bomb(){//홀수초에 폭탄이 터지는 경우: save에서 폭탄이 터진결과를 arr에 갱신하고, 그 arr의 save에도 다시 저장한다.
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(save[i][j]=='O'){
                int x=i; int y=j;
                arr[x][y]='.'; //현재 좌표 터뜨리기.
                for(int k=0; k<4; k++){ //인접한 칸 터뜨리기
                    int nx=x+dx[k]; 
                    int ny=y+dy[k];
                    if(nx>=0 && ny>=0 && nx<r && ny<c){
                        arr[nx][ny]='.';
                        
                    }
                }
            }
        }
    }

    //save에 arr의 결과 저장하기
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            save[i][j]=arr[i][j]; //save 배열에 arr 배열 저장하기.
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>r>>c>>n;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>arr[i][j];
            save[i][j]=arr[i][j];
        }
    }

    if(n==1){ //1초후는 그대로
        printArr();
        return 0;
    }

    for(int i=1; i<=n; i++){
        if(i==1)
            continue;

        if(i%2==0){ // 짝수초면 폭탄 전체 설치하기
            install();
        }else{ //홀수초면 폭탄이 폭발.
            bomb();
        }
    }

    printArr();
    
}