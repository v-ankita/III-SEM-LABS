#include <iostream>
using namespace std;
 
class Node{
public:
    Node* lchild;
    int data;
    Node* rchild;
};
 
class Tree{
private:
    Node* root;
public:
    Tree();
    void CreateTree();
    int Height(Node* p);
    int Height() { return Height(root); }
    void iterativePreorder(Node* p);
    void iterativePreorder() { iterativePreorder(root); }
    void iterativeInorder(Node* p);
    void iterativeInorder() { iterativeInorder(root); }
    void iterativePostorder(Node* p);
    void iterativePostorder() { iterativePostorder(root); }
};
 
class Stack{
private:
    int size;
    int top;
    Node** S;
public:
    Stack(int size);
    ~Stack();
    void push(Node* x);
    Node* pop();
    Node* peek(int index);
    int isFull();
    int empty();
    void display();
    Node* stackTop();
};
 
Stack::Stack(int size) {
    this->size = size;
    top = -1;
    S = new Node* [size];
}
 
Stack::~Stack() {
    delete[] S;
}
 
void Stack::push(Node* x) {
    if (isFull()){
        cout << "Stack Overflow!" << endl;
    } else {
        top++;
        S[top] = x;
    }
}
 
Node* Stack::pop() {
    Node* x;
    if (empty()){
        cout << "Stack Underflow!" << endl;
    } else {
        x = S[top];
        top--;
    }
    return x;
}
 
Node* Stack::peek(int index) {
    Node* x;
    if (top-index+1 < 0 || top-index+1 == size){
        cout << "Invalid position!" << endl;
    } else {
        x = S[top-index+1];
    }
    return x;
}
 
int Stack::isFull() {
    if (top == size-1){
        return 1;
    }
    return 0;
}
 
int Stack::empty() {
    if (top == -1){
        return 1;
    }
    return 0;
}
 
void Stack::display() {
    for (int i=top; i>=0; i--){
        cout << S[i] << " | " << flush;
    }
    cout << endl;
}
 
Node* Stack::stackTop() {
    Node* t= NULL;
    if (empty()){
        return t;
    }
    return S[top];
}
 

class Queue{
private:

public:
    int size;
    int front;
    int rear;
    Node** Q;  // [Node*]*: Pointer to [Pointer to Node]
    Queue(int size);
    bool isFull();
    bool empty();
    void enqueue(Node* x);
    Node* dequeue();
};
 
Queue::Queue(int size) {
    this->size = size;
    front = -1;
    rear = -1;
    Q = new Node* [size];
}

bool Queue::empty() {
    if (front == rear){
        return true;
    }
    return false;
}
 
bool Queue::isFull() {
    if (rear == size-1){
        return true;
    }
    return false;
}
 
void Queue::enqueue(Node* x) {
    if (isFull()){
        cout << "Queue Overflow" << endl;
    } else {
        rear++;
        Q[rear] = x;
    }
}
 
Node* Queue::dequeue() {
    Node* x = nullptr;
    if (empty()){
        cout << "Queue Underflow" << endl;
    } else {
        front++;
        x = Q[front];
    }
    return x;
}


Tree::Tree() {
    root = nullptr;
}

void Tree::CreateTree() {
    Node* p;
    Node* t;
    int x;
 
    Queue q(25);
    root = new Node;
    cout << "Enter root value: " << flush;
    cin >> x;
    root->data = x;
    root->lchild = nullptr;
    root->rchild = nullptr;
    q.enqueue(root);
 
    while (! q.empty()){
        p = q.dequeue();
 
        cout << "Enter left child value of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1){
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->lchild = t;
            q.enqueue(t);
        }
 
        cout << "Enter right child value of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1){
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}
 
int Tree::Height(Node *p) {
    int l = 0;
    int r = 0;
    if (p == nullptr){
        return 0;
    }
 
    l = Height(p->lchild);
    r = Height(p->rchild);
 
    if (l > r){
        return l + 1;
    } else {
        return r + 1;
    }
}
 
void Tree::iterativePreorder(Node *p) {
    Stack stk(25);
    while (p != nullptr || ! stk.empty()){
        if (p != nullptr){
            cout << p->data << ", " << flush;
            stk.push(p);
            p = p->lchild;
        } else {
            p = stk.stackTop();
            stk.pop();
            p = p->rchild;
        }
    }
    cout << endl;
}
 
void Tree::iterativeInorder(Node *p) {
    Stack stk(25);
    while (p != nullptr || ! stk.empty()){
        if (p != nullptr){
            stk.push(p);
            p = p->lchild;
        } else {
            p = stk.stackTop();
            stk.pop();
            cout << p->data << ", " << flush;
            p = p->rchild;
        }
    }
    cout << endl;
}
 
 //POSTORDER DOESN'T WORK!!
void Tree::iterativePostorder(Node *p) {
    Stack stk(25);
    Node* temp;
    while (p != nullptr || !stk.empty()){
        if (p != nullptr){
            stk.push(p);
            p = p->lchild;
        } else {
            
            temp = stk.stackTop();
            stk.pop();
            if (temp->data > 0){
                stk.push(temp);
                p = ((Node*)temp)->rchild;
            } else {
                cout << temp->data << ", " << flush;
                p = nullptr;
            }
        }
    }
}
 
 
int main() {
 
    Tree bt;
 
    bt.CreateTree();
    cout << endl;
 
    cout << "Height: " << bt.Height() << endl;
 
    cout << "Iterative Preorder: " << flush;
    bt.iterativePreorder();
 
    cout << "Iterative Inorder: " << flush;
    bt.iterativeInorder();
 
    cout << "Iterative Postorder: " << flush;
    bt.iterativePostorder();
 
    return 0;
}