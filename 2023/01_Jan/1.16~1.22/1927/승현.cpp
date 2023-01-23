#include <iostream>
#include <set>
// #include <queue>
using namespace std;
int n;
multiset<int> myqueue;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int tmp;
        scanf("%d", &tmp);
        if(tmp == 0) {
            if(myqueue.empty()) printf("0\n");
            else{
                printf("%d\n", *myqueue.begin());
                myqueue.erase(myqueue.begin());
            }
            
        }
        else{
            myqueue.insert(tmp);
        }
        // cout <<"=====new ary=====" << endl;
        // for(auto it : myqueue) cout << it <<"  ";
        // cout << endl << "===========" <<endl;
    }
}

