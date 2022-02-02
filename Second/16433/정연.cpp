#include <iostream>

using namespace std;

int main()
{
    int n,r,c;
    
    cin >> n >> r >> c;
    
    for(int i=0; i<n;i++){
        for(int j=0; j< n;j++){
            
            if(i%2==r%2 && j%2==c%2){
                cout << 'v';
            }
            else if(i%2!=r%2 && j%2 !=c%2){
                cout << 'v';
            }
            else{
                cout << '.';
            }
            
        }
        cout << endl;
    }

    return 0;
}
