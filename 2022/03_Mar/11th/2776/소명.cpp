// 2776번: 암기왕
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, n, m;
int arr[1000001];
bool func(vector<int> v, int target, int n)
{
    int start = 0;
    int end = n - 1;
    
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (v[mid] == target)
        {
            return true;
        }
        else if (v[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end= mid - 1;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--)
    {
        cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }

        sort(v.begin(), v.end());
    

        cin >> m;
        for (int i = 0; i < m; i++)
        {
            int y;
            cin>>y;
            // cout<<func(v,y,n)<<"\n";
            //만든함수 func쓰면 시간초과인데, 왜 이함수 쓰면 시간초과 안나는지 모르겠음
           if(binary_search(v.begin(),v.end(),y)) 
           cout<<1<<"\n";
           else
           cout<<0<<"\n";
        }
        

    }

}