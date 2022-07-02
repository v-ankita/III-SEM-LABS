//stacks using linked lists
#include <iostream>
using namespace std;
 
class Node{
public:
    int data;
    Node* next;
};
 
class Stack{

public:
	Node* top;
    Stack();

    void push(int x);
    int pop();
    int peek(int index);
    int isEmpty();
    int stackTop();
    void display();
};
 
Stack::Stack() {
    top = NULL;
}

 
void Stack::push(int x) {
    Node* t = new Node;
    if (t == NULL){
        cout << "Stack Overflow!" << endl;
    } else {
        t->data = x;
        t->next = top;
        top = t;
    }
}
 
int Stack::pop() {
    Node* p;
    int x = -1;
    if (top == NULL){
        cout << "Stack Underflow!" << endl;
    } else {
        p = top;
        x = p->data;
        top = top->next;
        delete p;
    }
    return x;
}

void Stack :: display()
{
 struct Node *p;
 p=top;
 while(p!=NULL)
 {
	cout<<p->data<<" ";
 p=p->next;
 }
 cout<<endl;
}

int Stack::isEmpty() {
    return top ? 0 : 1;
}
 
int Stack::stackTop() {
    if (top){
        return top->data;
    }
    return -1;
}
 
int Stack::peek(int index) {
    if (isEmpty()){
        return -1;
    } else {
        Node* p = top;
 
        for (int i=0; p != NULL && i<index-1; i++){
            p = p->next;
        }
 
        if (p != NULL){
            return p->data;
        } else {
            return -1;
        }
    }
}
 
int main() {
 
 int num, x; 
 Stack stk;

cout<<"1- push()"<<endl; 

cout<<"2- pop()"<<endl; 

cout<<"3- display()"<<endl; 

cout<<"4- isEmpty()"<<endl; 

cout<<"5- To Exit"<<endl; 

do{ 

cout<<"Enter number from above to perform functions: "; 

cin>>num; 

if(num==1) 

{ 

cout<<"Enter value to be pushed: "; 

cin>>x; 

stk.push(x); 

continue; 

} 

else if(num==2) 

{ 

cout<<stk.pop()<<" popped"<<endl; 

} 

else if(num==3) 

{ 
stk.display();
} 

else if(num==4) 

{ 
	if(stk.isEmpty())
	cout<<"Stack is empty"<<endl;
	else
	cout<<"Stack is not empty"<<endl;
} 

else if(num==5) 

{ 

cout<<"Exiting..."<<endl;

} 

}while(num<5); 

return 0; 
}

