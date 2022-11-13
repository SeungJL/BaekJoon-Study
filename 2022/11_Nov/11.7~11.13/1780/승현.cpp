#include <iostream>
using namespace std;
int n;
int a[2188][2188];
bool isfull(int ra,int ca,int rb,int cb);
void stage(int ra,int ca,int rb,int cb);
int minonenum = 0;
int zeronum = 0;
int onenum = 0;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    // cout << "let's go" << endl;
    stage(1, 1, n, n);

    cout << minonenum << endl << zeronum << endl << onenum << endl;

}
bool isfull(int ra,int ca,int rb,int cb){
    bool ok = true;
    int cur_val = a[ra][ca];
    for(int i = ra; i <= rb; i++){
        for(int j = ca; j <=cb; j++){
            if(a[i][j] != cur_val){
                ok = false;
                break;
            }
        }
    }

    return ok;
}
void stage(int ra,int ca,int rb,int cb){
    // cout << "ra" << ra <<" ca" << ca << " rb" << rb <<" cb" << cb<<endl;
    if(isfull(ra, ca, rb, cb)){
        if(a[ra][ca] == -1) minonenum += 1;
        else if(a[ra][ca] == 0) zeronum += 1;
        else if(a[ra][ca] == 1) onenum += 1;
        else cout << "Error!" << endl;
    }else{
        int rnum = rb - ra + 1;
        int cnum = cb - ca + 1;
        if(rnum != cnum) cout << "rnum cnum different!" << endl;
        else if(rnum % 3 !=0) cout << "rnum not divided!" << endl;
        int numdiv = (int) (rnum / 3);
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                stage(ra + i * numdiv, ca + j * numdiv, ra + (i + 1) * numdiv - 1, ca + (j + 1) * numdiv - 1);
            }
        } 
    }
}