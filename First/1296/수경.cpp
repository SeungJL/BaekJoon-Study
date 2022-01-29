#include <bits/stdc++.h>

using namespace std;

int L, O, V, E;


int calculatePer(string str){
    for(int i=0;i<str.size();i++){
        if(str[i] == 'L') L++;
        else if(str[i] == 'O') O++;
        else if(str[i] == 'V') V++;
        else if(str[i] == 'E') E++;
    }
    int percent = ((L+O)*(L+V)*(L+E)*(O+V)*(O+E)*(V+E))%100;
    return percent;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string name;
    cin >> name;

    for(int i=0;i<name.size();i++){
        if(name[i] == 'L') L++;
        else if(name[i] == 'O') O++;
        else if(name[i] == 'V') V++;
        else if(name[i] == 'E') E++;
    }

    int N;
    cin >> N;
    cin.get();
    int name_L = L, name_O = O,name_V = V,name_E = E;
    int max = 0;
    string winner;
    for(int i=0;i<N;i++){
        L = name_L; O = name_O; V = name_V; E = name_E;
        string teamName;
        cin >> teamName;
        if(i==0) winner = teamName;
        int per = calculatePer(teamName);

        if(per > max){
            winner = teamName;
            max = per;
        }
        else if(per == max){
            if(winner > teamName) winner = teamName;
        }
    }
    cout << winner << "\n";


    return 0;
}
