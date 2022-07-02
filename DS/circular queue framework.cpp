#include<iostream>
using namespace std;

class CirQueue
{
private:
	int front;
	int rear;
	int size;
	int *Q;
public:
	CirQueue(){front=rear=0; size=10; Q= new int[size]; }	
	CirQueue(int size){ front=rear=0; this->size=size; Q= new int[this->size];	}
	void enqueue(int x);
	int dequeue();
	void display();
	bool isEmpty();
	bool isFull();
};

void CirQueue :: enqueue(int x)
{
	if((rear+1)%size==front)
		cout<<"Queue full"<<endl;
	else
	{
		rear=(rear+1)%size;
		Q[rear]=x;
	}
}

int CirQueue :: dequeue()
{
	int x;
	if(front==rear)
		cout<<"Queue empty"<<endl;
	else
	{
		front=(front+1)%size;
		x=Q[front];
	}
	return x;
}

void CirQueue :: display()
{
	int i=front+1;
	do{
		cout<<Q[i]<<" ";
		i=(i+1)%size;
	}while(i!=(rear+1)%size);
	cout<<endl;
}

bool CirQueue :: isEmpty()
{
	if(front==rear)
		return true;
	else
		return false;
}

bool CirQueue :: isFull()
{
	if((rear+1)%size==front)
		return true;
	else
		return false;
}

int main()
{
	int n, val;
	CirQueue q;
	cout<<"Index numbers for different functions are:"<<endl;
	cout<<"Enter 1 for enqueue()"<<endl;
	cout<<"Enter 2 for dequeue()"<<endl;
	cout<<"Enter 3 for display()"<<endl;
	cout<<"Enter 4 for isEmpty()"<<endl;
	cout<<"Enter 5 for isFull()"<<endl;
	cout<<"Enter 6 to exit"<<endl;
	do{
		cout<<"Enter number: ";
		cin>>n;
		switch(n){
			case 1:
				{
					cout<<"Enter number to be inserted: ";
					cin>>val;
					q.enqueue(val);
					break;
				}
			case 2:
				{
					cout<<q.dequeue()<<" deleted from queue"<<endl;
					break;
				}
			case 3:
				{
					cout<<"Queue elements are:"<<endl;
					q.display();
					break;
				}
			case 4:
				{
					if(q.isEmpty())
						cout<<"The queue is empty"<<endl;
					else
						cout<<"The queue is not empty"<<endl;
					break;
				}
			case 5:
				{
					if(q.isFull())
						cout<<"The queue is full"<<endl;
					else
						cout<<"The queue is not full"<<endl;
					break;
				}
			case 6:
				{
					cout<<"Exiting..."<<endl;
					break;
				}
			default: cout<<"Invalid index"<<endl;
		}
	}while(n!=6);
	
	return 0;
}


