#include <iostream>
#include <string>
using namespace std;

//최대공약수 
int gcd(int n,int m){
    if(n%m==0)
    return m;
    else
    return gcd(m,n%m);

}

// n과 m의 최대공약수로 각각의 수를 나누면 최대한 약분한 값이 된다.

string s;
string temp;
int n,m;

int main(){
    cin>>s;
    
    //문자열 입력받아서 n과 m반환하기
    for(int i=0; i<s.size(); i++){
        if(s[i]==':'){
            //n 구하기
            temp=s.substr(0,i);
            n=stoi(temp);

            //m 구하기
            temp=s.substr(i+1,s.length());
            m=stoi(temp);

            //:나오면 더이상 필요없으니까 break
            break;
            
        }
    }


    int num=gcd(n,m);
    cout<<n/num<<":"<<m/num; 
}