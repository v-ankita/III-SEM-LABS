//evaluation of prefix multidigit
#include <iostream>
using namespace std;

int top;
float stack[50];
int max_size = 50;

void push(int x) {
if(top == max_size - 1)
cout << "Stack Overflow";
else
stack[++top] = x;
}

float pop() {
if(top == -1)
cout << "Stack Underflow";
else
return stack[top--];
}

int power(int place) {
int ans = 1;
for(int i = 1; i <= place; i++)
ans *= 10;
return ans;
}

void evaluate_prefix(char prefix[100]) {
top = -1;
int i = 0;
for( ; prefix[i] != '\0'; i++);
i--;
while(i >= 0) {
float num = 0;
int place = 0;
if(prefix[i] >= 48 && prefix[i] <= 57) {
for( ; prefix[i] != ' '; i--) {
int digit = (int)prefix[i] - 48;
num += digit * power(place);
place++;
}
push(num);
i--;
}
else if(prefix[i] == ' ')
i--;
else {
float a, b;
a = pop();
b = pop();
if(prefix[i] == '*')
a = a * b;
else if(prefix[i] == '/')
a = a / b;
else if(prefix[i] == '+')
a = a + b;
else
a = a - b;
push(a);
i--;
}
}
cout << "Prefix evaluation = " << stack[top];
}

int main() {
char  prefix[100];
cout << endl << "Enter an prefix expression: ";
gets(prefix);
evaluate_prefix(prefix);
return 0;
}

