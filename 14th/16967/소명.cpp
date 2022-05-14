//16967번: 배열 복원하기
//몰라서 구글링함... https://allmymight.tistory.com/m/11

/*
H, W, X, Y
2<=H,W<=300
1<=X<H
1<=Y<W
0<=B(i,j) <=1,000

*/
#include <iostream>
using namespace std;
int arr[600][600]; //주어지는 배열
// int a[300][300]; //구하려는 배열
int h,w,x,y;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>h>>w>>x>>y;
    //b배열 입력받기
    for(int i=0; i<h+x; i++){
        for(int j=0; j<w+y; j++){
            cin>>arr[i][j];
        }
    }

    //원래배열(a)구하기
    for(int i=x; i<h; i++){
        for(int j=y; j<w; j++){
            arr[i][j]=arr[i][j]-arr[i-x][j-y];
        }
    }

    //원래 배열 출력
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
}