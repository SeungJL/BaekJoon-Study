#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    
    long long result = ceil(sqrt(n));
    
    cout << result<< endl;

    return 0;
}
