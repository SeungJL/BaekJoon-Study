#include <iostream>
#include <algorithm>

using namespace std;
 

int main() {
    string s;
    int n,d,m,y;
    int birth[100];
    string name[100];
    int rmax=0,rmin=1000000000;
    int imax,imin;
    
    cin >> n;
    
    for(int i=0; i<n;i++){
        cin >> s >> d >> m >> y;
        name[i]=s;
        birth[i]=y*365*30+m*30+d;
        if(rmax < birth[i]){
            rmax = birth[i];
            imax = i;
        }
        if(rmin > birth[i]){
            rmin = birth[i];
            imin = i;
        }
    }
    
    cout << name[imax] << "\n" << name[imin];
   
    
    return 0;
}
