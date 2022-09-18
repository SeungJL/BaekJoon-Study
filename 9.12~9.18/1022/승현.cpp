#include<bits/stdc++.h>
using namespace std;
int r1,c1,r2,c2;
// int a[10001][10001];
void get_matrix();
void get_matrix2();
void get_print(int, int);
int main(){
    cin>>r1>>c1>>r2>>c2;
    get_matrix2();
    
    

}
void get_matrix2(){
    int cnt=0;
    int real_r = max(abs(r1), abs(r2));
    int real_c = max(abs(c1), abs(c2));
    int max_side = max(real_r, real_c);
    int max_dig = 0;
    // cout<<"max dig"<< max_dig<<endl;
    for(int i=1; i <= 2*max_side + 1;i++){
        // bool enter = true;
        for(int j=1; j<=2*max_side + 1;j++){
            int symi = i - max_side - 1;
            int symj = j - max_side - 1;
            if(symi < r1 || symi > r2 || symj < c1 || symj > c2){
                continue;
            } 
            int round = max(abs(symi), abs(symj));
            if(symi == round){
                int tok = round - symj;
                max_dig = max(max_dig, (int) pow(2 * round + 1, 2) - tok);

            } else if(symi == -round){
                int tok  =  round - symj;
                max_dig = max(max_dig, (int) pow(2 * round +1, 2) - 6 * round  + tok);
            } else if (symj == round){
                int tok = round - symi;
                max_dig = max(max_dig, (int) pow(2 * (round - 1) +1, 2) + tok);
            } else{
                int tok = round - symi;
                max_dig = max(max_dig, (int) pow(2 * round +1, 2) - 2 * round - tok);
            }
        }
    }
    max_dig = to_string(max_dig).length();
    for(int i=1; i <= 2*max_side + 1;i++){
        bool enter = true;
        for(int j=1; j<=2*max_side + 1;j++){
            int symi = i - max_side - 1;
            int symj = j - max_side - 1;
            if(symi < r1 || symi > r2 || symj < c1 || symj > c2){
                if(symi < r1 || symi > r2){
                    enter = false;
                }
                continue;
            } 
            int round = max(abs(symi), abs(symj));
            if(symi == round){
                int tok = round - symj;
                get_print(max_dig, pow(2 * round + 1, 2) - tok);

            } else if(symi == -round){
                int tok  =  round - symj;
                get_print(max_dig, pow(2 * round +1, 2) - 6 * round  + tok);
            } else if (symj == round){
                int tok = round - symi;
                get_print(max_dig, pow(2 * (round - 1) +1, 2) + tok);
            } else{
                int tok = round - symi;
                get_print(max_dig, pow(2 * round +1, 2) - 2 * round - tok);
            }
        }
        if(enter) cout << endl;
    }
}
void get_print(int max_dig, int num){
    string snum = to_string(num);
    string blank;
    for(int i=1; i<= max_dig - snum.length(); i++){
        blank += " ";
    }
    cout << blank + snum << " ";
}
