#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int x[26];

double PostCalculator(string s){
    stack<double> stack;
    char tok;
    for(int i=0; i<s.size();i++){
        tok = s[i];
        
        if(s[i]>='A' && s[i]<='Z'){
            stack.push(x[s[i]-'A']);
        } else{
            double op2 = stack.top();stack.pop();
            double op1 = stack.top();stack.pop();
            
            switch(tok){
                case '+':
                    stack.push(op1+op2);
                    break;
                case '-':
                    stack.push(op1-op2);
                    break;
                case '*':
                    stack.push(op1*op2);
                    break;
                case '/':
                    stack.push(op1/op2);
                    break;
            }
            
        }
        
    }
    
    return stack.top();
}

int main()
{
    int n;
    string s;
    cin >> n >> s;
    
    for(int i=0; i<n; i++){
        cin >> x[i];
    }
    
    cout << fixed;
    cout.precision(2);
    cout << PostCalculator(s);
	
}