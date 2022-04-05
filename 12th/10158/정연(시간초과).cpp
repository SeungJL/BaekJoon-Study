#include <iostream>
#include <string>
using namespace std;


int main() {
    
    int w, h;
    
    cin >> w >> h;
    
    int p, q, t;
    
    cin >> p >> q >> t;

    int dx=1, dy=1;
    
    for(int i=0; i<t; i++){
        if(p==w || p==0){
            dx*=-1;
        }
        if(q==h || q==0){
            dy*=-1;
        }
        p=p+dx;
        q=q+dy;
        
    }
    
    cout << p << " " << q; 
    
	return 0;
}