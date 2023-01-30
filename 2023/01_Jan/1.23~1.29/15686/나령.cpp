// 15686] 치킨 배달
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int,int> > chicken;
vector<pair<int,int> > hs; //house
int m, res=2147000000, dis, sum;
int ch[20]; //조합의 원소들을 넣을 배열 

void DFS(int L, int s){
	if(L==m){ //m개 숫자로 구성된 조합 하나가 완성이 되면 
		sum=0;
		for(int i=0; i<hs.size(); i++){
			//집 한개를 선택하고 
			int x1=hs[i].first;
			int y1=hs[i].second;
			
			
			//집-치킨집 거리 구하기 
			dis=2147000000;
			for(int j=0; j<m; j++){
				int x2=chicken[ch[j]].first;
				int y2=chicken[ch[j]].second;
				
				//거리 최솟값
				dis=min(dis, abs(x1-x2)+abs(y1-y2));
			}
			sum+=dis; //sum: 도시의 치킨배달거리 
		}
		if(sum<res) res=sum; //res: 도시의 최소 치킨배달거리 
		  
	}else{ 
		for(int i=s; i<chicken.size(); i++){ //0부터 시작, chicken.size()까지 
			ch[L]=i; //L로 index control하면서 숫자들을 하나씩 넣어봄 
			DFS(L+1, i+1);
		} 
	}
	
}
int main() {
	//freopen("input.txt","rt", stdin);
	int n, a;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++){
 		for(int j=1; j<=n; j++){
			 scanf("%d", &a);
			 if(a==1) hs.push_back(make_pair(i,j));
			 else if(a==2) chicken.push_back(make_pair(i,j));
		}
	}
	DFS(0,0);
	printf("%d", res);
	return 0;
}