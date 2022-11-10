#include <iostream>
using namespace std;


int main(){
	
	int n, a , b;
	
	cin >> n >> a >> b;
	
	int cnt =0;
	while(a!=b){
	
		a=(a+1)/2;
		b=(b+1)/2;
		cnt++;
	}
	
	cout << cnt << endl;
	
	
    return 0;
}


