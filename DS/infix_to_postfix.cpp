// convert infix expression to postfix
#include<iostream>
# include<string>
using namespace std;

int n=25, top=-1;
char stack[25];

void push(int x)
{
	top++;
	stack[top]=x;
}
void pop()
{
	top--;
}
bool empty()
{
	if(top==-1)
	return true;
	else
	return false;
}

int prec(char c) {
    if(c == '^')
        return 3;
    else if(c == '/' || c=='*')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void infixToPostfix(string s) {

    string result;
    for(int i = 0; i < s.length(); i++) {
        char c = s[i];
 
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            {result += c;
            cout << result << endl;}
 
        else if(c == '(')
            push('(');
 
        else if(c == ')') {
            while(top != '(')
            {
                
                result += top;
                cout << result << endl;
                pop();
            }
            pop();
        }
 
        else {
            while(!empty() && prec(s[i]) <= prec(top)) {
                result += top;
                cout << result << endl;
                pop(); 
            }
            push(c);
        }
    }
    while(!empty()) {
        result += top;
        pop();
        cout << result << endl;
    }
 
    cout << result << endl;
}
 
int main() {
    string exp;
    cout<<"Enter the expression: ";
    cin>>exp;
    infixToPostfix(exp);
    return 0;
}
