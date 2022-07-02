#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

class LinkedList
{
public:
    struct Node *first;
    LinkedList() { first = NULL; }

    ~LinkedList();

    void Display();
    void Insert(int index, int x);
    int Delete(int index);
    int Length();
};

LinkedList::~LinkedList()
{
    struct Node *p = first;
    while (first)
    {
        first = first->next;
        delete p;
        p = first;
    }
}
void LinkedList::Display()
{
    struct Node *p = first;

    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int LinkedList::Length()
{
    struct Node *p = first;
    int len = 0;

    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}
void LinkedList::Insert(int index, int x)
{
    Node *t, *p = first;

    if (index < 0 || index > (Length() + 2))
        return;

    t = new struct Node;
    t->data = x;
    t->next = NULL;

    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }

        t->next = p->next;
        p->next = t;
    }
}
int LinkedList::Delete(int index)
{
    struct Node *p, *q = NULL;
    int x = -1;

    if (index < 1 || index > Length())
        return -1;
    if (index == 1)
    {
        p = first;
        first = first->next;
        x = p->data;

        delete p;
    }
    else
    {
        p = first;
        for (int i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
    }
    return x;
}

main()
{
    LinkedList l;
    int n, i, val;
    cout << "Enter number of values: ";
    cin >> n;
    cout << "Enter values: ";
    for (i = 0; i < n; i++)
    {
        cin >> val;
        l.Insert(i, val);
    }

    cout << "List Created: ";
    l.Display();
    
    LinkedList a;
    struct Node* b =l.first;
    int j=0, sum=0;
    for(i=0;i<n;i++)
    {
    	if(i%2!=0)
    	{
    		a.Insert(j,b->data);
    		sum+=b->data;
			j++	;
		}
    	b=b->next;
	}

    if (n % 2 != 0)
    {
        int d = l.Delete((n + 1) / 2);
        l.Insert(n-1, d);
    }

    struct Node *p = l.first;
    cout << "Front list: ";
    for (i = 0; i < n / 2; i++)
    {
        cout << p->data << " ";
        p = p->next;
    }

    cout << "\nTail list: ";
    for (i = (n / 2) + 1; i < n + 1; i++)
    {
        cout << p->data << " ";
        p = p->next;
    }
    
    cout << "\nAlt list: ";
    a.Display();
    
    cout<<"Sum: "<<sum;
}
