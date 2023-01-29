#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[51][51];
vector<pair<int,int>> home;
vector<pair<int,int>> chicken;
int shortest[100][13];
int ans=0x7fffffff;
void dfs(int,vector<int>&);
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
            if(a[i][j]==1)
            {
                home.push_back(make_pair(i,j));
            }
            if(a[i][j]==2)
            {
                chicken.push_back(make_pair(i,j));
            }
        }
    }
    for(int i=0;i<home.size();i++)
    {
        for(int j=0;j<chicken.size();j++)
        {
            shortest[i][j]=abs(home[i].first-chicken[j].first)+abs(home[i].second-chicken[j].second);
        }
    }
    vector<int> visit;
    dfs(0,visit);
    cout<<ans<<endl;


}
void dfs(int idx,vector<int>& visit)
{
    // cout<<"idx"<<idx<<endl;
    // for(auto it:visit) cout<<it<<" ";
    // cout<<endl;
    if(visit.size()>m||idx>chicken.size()) return;
    if(idx==chicken.size()&&visit.size()==m)
    {
        int part_ans=0;
        for(int i=0;i<home.size();i++)
        {
            int home_ans=0x7fffffff;
            for(auto visit_idx:visit)
            {
                home_ans=min(home_ans,shortest[i][visit_idx]);
            }
            part_ans+=home_ans;
        }
        ans=min(ans,part_ans);
    }
    else
    {
        visit.push_back(idx);
        dfs(idx+1,visit);
        visit.pop_back();
        dfs(idx+1,visit);
    }
}