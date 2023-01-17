#include <iostream>
#include <algorithm>

using namespace std;
int arr[200001] = { 0, };
int n, c;
int answer = 0;
void binary_search(int start, int end) {

    if(start > end) return;

    int mid = (start + end) / 2;
    int prev_house = arr[0];
    int count = 1;
    for(int i=1; i<n; i++) {
        if(arr[i] - prev_house >= mid) {
            prev_house = arr[i];
            count++;
        }
    }

    // cout << mid << " " << count << "\n";

    if(count >= c) {
        if(mid > answer) {
            answer = mid;
        }
        binary_search(mid + 1, end);
    } else {
        binary_search(start, mid - 1);
    }
}

int main() {
    
    cin >> n >> c;

    for(int i=0; i<n; i++) {
        int input;
        cin >> input;
        arr[i] = input;
    }
    
    sort(arr, arr+n);
    binary_search(1, arr[n-1] - arr[0]);
    cout << answer;
}