
//Program to evaluate a Postfix expression
#include <iostream>
#include <stdlib.h>
using namespace std;

class Stack {
    private:
    int top;
    int arr[100];
    public:
    Stack(){
        top=-1;
    }
    void push(int elem){
        if(top<100){
            arr[++top]=elem;
        }
        else{
            cout<<"Overflow"<<endl;
        }
    }
    int pop(){
        if(top>=0)
            return arr[top--];
        cout<<"Stack Underflow!"<<endl;
        return -1;
    }
    int peek(){
        if(top>=0)
            return arr[top];
        else{
            cout<<"Underflow"<<endl;
            return -1;
        }
    }
    void display(){
        for(int i=top;i>=0;i--){
            cout<<arr[i]<<endl;
        }
    }
};
int Operator(char ch, int a, int b){
    switch(ch){
        case '*': return(a*b);break;
        case '+': return(a+b);break;
        case '-': return(a-b);break;
        case '/': return(a/b);break;
        case '$': return(a^b);break;
        case '^': return(a^b);break;
        default:
        return 0;
    }
}
int postEval(string post){
    Stack s;
    int l=post.length();
    for(int i=0;i<l;i++){
        if(post[i] >= '0' && post[i] <= '9'){
            s.push(post[i]-'0');
       
        }
        else{
            s.push(Operator(post[i],s.pop(),s.pop()));
           
        }
        cout<<s.peek();
    }
    return s.peek();
}
int main(){
    string s;
    cout<<"Enter expression:";
    cin>>s;
    cout<<postEval(s);
}


