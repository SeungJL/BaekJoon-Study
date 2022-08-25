#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a;
set<string> answer;

//사전 순 정렬이라고 해서 set<string>을 썼는데,,,, 그렇게 접근하면 안 됐다.
//set<vector<int>> 중복 제거의 기준?
void get_permutation(std::vector<int>::size_type here, string s, int depth){
    if(depth == m){
        answer.insert(s);
        //cout << "return " << s << "\n";
        return;
    }

    for(std::vector<int>::size_type i=here; i < a.size(); i++){
        get_permutation(i+1, s + to_string(a[i]) + " ",  depth + 1);    
    }  

    return;
}


//n과 m (10)
/*
next_permutation으로 해결할 수 없는 이유
1. 오름차순 정렬
2. operator < 을 사용하여 순열 생성
3. 중복이 있는 원소들을 제거됨
*/

int main(){
    cin >> n >> m;

    int temp;
    for(int i=0; i < n; i++){
        cin >> temp;
        a.push_back(temp);
    }
    
    //오름차순으로 정렬
    sort(a.begin(), a.end());
    get_permutation(0, "", 0);

    set<string>::iterator iter;
    for(iter=answer.begin(); iter != answer.end(); iter++){
        cout << stoi(*iter) << "\n";
    }

    /*
    8 4
    1 1 1 1 2 2 2 2
    */

   /*
   4 2
   999 1 23 5
   */
}