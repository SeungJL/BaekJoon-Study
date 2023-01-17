#include <iostream>
#include <algorithm>
using namespace std;
int arr[10001] = { 0, };
int n, m;
int answer = 0;

void binary_search(int start, int end) {
    if(start > end) return;

    int mid = (start + end) / 2;


    int temp = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] <= mid) {
            temp += arr[i];
        } else {
            temp += mid;
        }
    }

    // cout << start << " " << end << " " << temp << "\n";
    if(temp > m) {
        binary_search(start, mid - 1);
    } else {
        if(mid > answer) {
            answer = mid;
        }
        binary_search(mid + 1, end);
    }
}

int main(){ 
    cin >> n;

    for(int i=0; i<n; i++) {
        int input;
        cin >> input;
        arr[i] = input;
    }

    cin >> m;

    sort(arr, arr + n);
    binary_search(0, arr[n-1]);

    cout << answer;
}