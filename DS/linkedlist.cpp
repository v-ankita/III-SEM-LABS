#include <iostream>
using namespace std;

struct Node
{
 int data;
 struct Node *next;
};

class LinkedList
{
	private:
 		struct Node *first;
	public:
 	LinkedList(){first=NULL;}

 	~LinkedList();

	void Display();
 	void Insert(int index,int x);
 	int Delete(int index);
 	int Length();
};

LinkedList::~LinkedList()
{
 struct Node *p=first;
 while(first)
 {
 first=first->next;
 delete p;
 p=first;
 }
}
void LinkedList::Display()
{
 struct Node *p=first;

 while(p)
 {
 cout<<p->data<<" ";
 p=p->next;
 }
 cout<<endl;
}

int LinkedList::Length()
{
 struct Node *p=first;
 int len=0;

 while(p)
 {
 len++;
 p=p->next;
 }
 return len;
}
void LinkedList::Insert(int index,int x)
{
 Node *t,*p=first;

 if(index <0 || index > Length())
 return;
 t=new struct Node;
 t->data=x;
 t->next=NULL;

 if(index==0)
 {
 t->next=first;
 first=t;
 }
 else
 {
 for(int i=0;i<index-1;i++)
 p=p->next;
 t->next=p->next;
 p->next=t;
 }
}
int LinkedList::Delete(int index)
{
 struct Node *p,*q=NULL;
 int x=-1;

 if(index < 1 || index > Length())
 return -1;
 if(index==1)
 {
 p=first;
 first=first->next;
 x=p->data;

 delete p;
 }
 else
 {
 p=first;
 for(int i=0;i<index-1;i++)
 {
 q=p;
 p=p->next;
 }
 q->next=p->next;
 x=p->data;

 delete p;
 }
 return x;
}
int main()
{

	LinkedList l;

	int num, val;
	cout<<"Enter 1 to insert element in the beggining of list" <<endl
	<<"2 to insert at the end of list"<<endl<<"3 to insert in between"<<endl
	<<"4 to delete an element"<<endl<<"5 to display elements"<<endl<<"6 to exit"<<endl;
	cout<<endl;
	do{
		cout<<"Enter number: ";
		cin>>num;
		switch(num){
			case 1:
				{
					cout<<"Enter number to be inserted in the beggining: ";
					cin>>val;
					l.Insert(0,val);
					break;
				}
			case 2:
				{
					cout<<"Enter number to be inserted in the end: "<<endl;
					cin>>val;
					l.Insert(l.Length(),val);
					break;
				}
			case 3:
				{
					int pos;
					cout<<"Enter position 1 to insert after 1st and before 2nd element, "<<endl<<"position 2 to insert after 2nd and before 3rd element and so on:"<<endl;
					cin>>pos;
					cout<<"Enter element to be inserted at the position: "<<endl;
					cin>>val;
					l.Insert(pos,val);
					break;
				}
			case 4:
				{
					cout<<"Enter index of element to be deleted ";
					cin>>val;
					cout<<"Deleted "<<l.Delete(val)<<endl;
					break;
				}
			case 5:
				{
					cout<<"The list elements are:"<<endl;
					l.Display();
					break;
				}
			case 6:
				{
					cout<<"Exiting..."<<endl;
					break;
				}
			default: cout<<"Invalid index"<<endl;
		}
	}while(num!=6);
 return 0;
}
