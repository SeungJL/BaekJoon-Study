#include <iostream>
#include <algorithm>
using namespace std;

int x, cntl=0, cntr=0;

void search(int a, int b){
    if(a==1){
        cntr += b-1;
        return;
    }
     if(b==1){
        cntl += a-1;
        return;
    }
    if(a > b){
        x = a-b;
        cntl++;
        search(x, b);
    }
    else{
        x = b-a;
        cntr++;
        search(a,x);
    }
}


int main()
{
    int A, B;
    cin >> A >> B;
    
    search(A, B);
    
    cout << cntl << " " << cntr << "\n";

    return 0;
}
