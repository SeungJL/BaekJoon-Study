#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

vector<int> v[51];
vector<int>::iterator iter;
void run(int now)
{

    for(int i=0;i<v[now].size();i++)
    {

        run(v[now][i]);
    }
    v[now].push_back(-1);
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    cin.sync_with_stdio(false);

    int n,x;cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>x;
        v[x].push_back(i);
    }
    cin>>x;
    run(x);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            if(v[i][j]==x)
            {
                iter=v[i].begin()+j;

                v[i].erase(iter);
            }
        }
    }

    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(v[i].empty())
        {
            ans++;
        }
    }
    cout<<ans<<endl;
}
