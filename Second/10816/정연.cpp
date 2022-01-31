#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int main()
{
   int n, m;
   vector<int> v;
   
   cin >> n;
   v.resize(n);
   
   for(int i=0; i<n;i++){
       cin >> v[i];
   }
   
   sort(v.begin(), v.end());
   
   cin >> m;
   int x,cnt =0; 
   for(int i=0; i<m ; i++){
        cin >> x;
        auto upper = upper_bound(v.begin(),v.end(),x);
        auto lower = lower_bound(v.begin(),v.end(),x);
        
        cout << upper - lower <<" ";
   }
    

    return 0;
}
