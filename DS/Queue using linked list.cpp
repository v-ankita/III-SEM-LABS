//queue using linked lists
#include <iostream>
using namespace std;

struct Node
{
 int data;
 struct Node *next;
}*top=NULL;

struct qNode{
int qdata;
struct qNode *qnext;
}*front=NULL,*rear=NULL;

void enqueue(int x)
{
 struct qNode *t;
 t=new qNode;
 if(t==NULL)
 printf("Queue is FUll\n");
 else
 {
 t->qdata=x;
 t->qnext=NULL;
 if(front==NULL)
 front=rear=t;
 else
 {
 rear->qnext=t;
 rear=t;
 }
 }

}
int dequeue()
{
 int x=-1;
 struct qNode* t;
if(front==NULL)
 cout<<"Queue is Empty"<<endl;
 else
 {
 x=front->qdata;
 t=front;
 front=front->qnext;
 delete(t);
 }
 return x;
}
void qDisplay()
{
 struct qNode *p=front;
 while(p)
 {
 printf("%d ",p->qdata);
 p=p->qnext;
 }
 printf("\n");
}

int main()
{
	int y,chq;
	 cout<<"enter 1.enqueue"<<endl;
     cout<<"enter 2.dequeue"<<endl;
     cout<<"enter 3.display"<<endl;
     do{
     cout<<"enter choice"<<endl;
     cin>>chq;
     switch(chq){
         case 1:
             cout<<"enter element to enqueue"<<endl;
             cin>>y;
             enqueue(y);
             break;
         case 2:
            dequeue();
            break;
         case 3:
            qDisplay();
            break;
         default:
            cout<<"INVALID CHOICE"<<endl;
            break;
     }
}while(chq<=3);
}

