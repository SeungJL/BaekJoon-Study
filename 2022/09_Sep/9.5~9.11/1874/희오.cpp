#include <iostream>

using namespace std;

int n;
int *seq, *stack;
int top = -1;
string res = "";

void my_push(int input) {
	stack[++top] = input;
	res += "+\n";
}

void my_pop() {
	stack[top--] = 0;
	res += "-\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen("input.txt", "rt", stdin);

	// init
	int input;

	cin >> n;
	seq = new int[n];
	for(int i=0; i<n; i++) {
		cin >> input;
		seq[i] = input;
	}
	
	// solve
	input = 1;	
	stack = new int[n];
	int *target = seq;

	while(target < seq + n ) {
		if (top == -1 || stack[top] < *target) {
			do {
				if (input <= n)
					my_push(input++);
			} while(stack[top] != *target);
		}

		if (stack[top] == *target) {
			my_pop();
			target++;
		}
		else {
			cout << "NO\n";
			return 0;
		}
	}
	cout << res;
}