#include <bits/stdc++.h>

using namespace std;


bool compare(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

vector<pair<int, int>> korean;
vector<pair<int, int>> english;
vector<pair<int, int>> math;
vector<pair<int, int>> science;
vector<int> ans;
int main(){
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        int id, k, e, m, s;
        cin >> id >> k >> e >> m >> s;
        korean.push_back(make_pair(k, id));
        english.push_back(make_pair(e, id));
        math.push_back(make_pair(m, id));
        science.push_back(make_pair(s, id));
    }

    sort(korean.begin(), korean.end(), compare);
    ans.push_back(korean[0].second);

    for(int i=0;i<N;i++){
        if(english[i].second == korean[0].second) english.erase(english.begin()+i);
    }
    for(int i=0;i<N;i++){
        if(math[i].second == korean[0].second) math.erase(math.begin()+i);
    }
    for(int i=0;i<N;i++){
        if(science[i].second == korean[0].second) science.erase(science.begin()+i);
    }


    sort(english.begin(), english.end(), compare);
    ans.push_back(english[0].second);

    for(int i=0;i<N-1;i++){
        if(math[i].second == english[0].second) math.erase(math.begin()+i);
    }
    for(int i=0;i<N-1;i++){
        if(science[i].second == english[0].second) science.erase(science.begin()+i);
    }


    sort(math.begin(), math.end(), compare);
    ans.push_back(math[0].second);

    for(int i=0;i<N-2;i++){
        if(science[i].second == math[0].second) science.erase(science.begin()+i);
    }


    sort(science.begin(), science.end(), compare);
    ans.push_back(science[0].second);

    for(int i=0;i<4;i++) cout << ans[i] << " ";


    return 0;
}