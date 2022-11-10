#include <bits/stdc++.h>

using namespace std;

//나라 구조체 선언
typedef struct Country {
    int name;
    int gold;
    int silver;
    int bronze;
} Country;

int K;

bool compare(Country a, Country b) {
    //금메달의 개수가 같은 경우
    if (a.gold == b.gold) {
        //은메달의 개수가 같은 경우
        if (a.silver == b.silver) {
            //동매달의 개수가 같은 경우
            if (a.bronze == b.bronze) {
                //해당 국가가 등수를 알고싶은 국가면,
                //동점인 국가 중 가장 앞쪽으로 정렬해야
                //해당 국가보다 성적이 좋은 국가의 개수를 통해 순위를 수 있음.
                if (a.name == K) {
                    return true;
                }
                if (b.name == K) {
                    return false;
                }
            }
            return a.bronze > b.bronze;
        }
        return a.silver > b.silver;
    }
    return a.gold > b.gold;
}

int main() {

    int N;
    scanf("%d %d", &N, &K);

    Country *countries = new Country[1000];
    for (int i = 0; i < N; i++) {
        cin >> countries[i].name >> countries[i].gold >> countries[i].silver >> countries[i].bronze;
    }

    //compare 함수를 통하여 구조체 정렬하기
    sort(countries, countries + N, compare);


    //처음부터 알고싶은 국가가 나올 때까지 순회하기. 
    for (int i = 0; i < N; i++) {
        if (K == countries[i].name) printf("%d", i + 1);
    }
    return 0;
}