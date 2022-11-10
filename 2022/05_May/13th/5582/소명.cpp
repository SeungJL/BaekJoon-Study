//5582번: 공통 부분 문자열
/*
첫째 줄과 둘째 줄에 문자열이 주어진다. 
문자열은 대문자로 구성되어 있으며, 길이는 1 이상 4000 이하이다.
*/

//몰라서 구글링함..
//참고 : https://gusdnr69.tistory.com/111

#include <iostream>
#include <string>

using namespace std;

string s1, s2;
int answer=0;
int d[4000][4000];


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s1;
    cin>>s2;

//시간초과 코드
//s.substr(i,j) : 문자열s의 i번 인덱스부터 j개 문자만큼 파싱

//    for(int i=0; i<s1.size()-1; i++){
//        for(int j=2; j<=s1.size()-i; j++){
//            cur1=s1.substr(i,j);

//             for(int i=0; i<s2.size()-1; i++){
//                 for(int j=2; j<=s2.size()-i; j++){
//                 cur2=s2.substr(i,j);

//                 if(cur1==cur2){
//                     if(answer<cur1.size()){
//                         answer=cur1.size();
//                     }
//                 }

//                 }
//             }
//         }
//     }

//표 세로가 s1, 가로가 s2라고 가정

    for(int i=0; i<s2.size(); i++){
        if(s1[0]==s2[i]){
            d[0][i]=1;
            answer=1;
        }
    }

    for(int i=0; i<s1.size(); i++){
        if(s2[0]==s1[i]){
            d[i][0]=1;
            answer=1;
        }
    }

    for(int i=1; i<s1.size(); i++){ //행(s1)
        for(int j=1; j<s2.size(); j++){ //열(s2)
            if(s1[i]==s2[j]){
                d[i][j]=d[i-1][j-1]+1;
                if(answer<d[i][j]) answer=d[i][j];
            }
        }
    }
    cout<<answer<<"\n";

}