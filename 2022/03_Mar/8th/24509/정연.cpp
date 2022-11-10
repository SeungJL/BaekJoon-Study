#include<iostream>
#include<map>
#include<vector>
using namespace std;

map<int, vector<int>> student;

int main() {
	
	int n, x;
	cin >> n;
	
	for(int i=0; i<n; i++){
	    cin >> x;
	    int score;
	    for(int j=0; j<4; j++){
	        cin >> score;
	        student[x].push_back(score);
	    }
	}
	for(int i=0; i<4; i++){
	   int max_score = -1;
	   int max_idx;
	   if(!student.empty()){
    	   for(auto a : student){
    	        if(a.second[i]>max_score){
    	            max_score = a.second[i];
    	            max_idx = a.first;
    	        }
    	    }
    	    student.erase(max_idx);
    	    cout << max_idx <<" ";
	   }
	}
	
    return 0;
}