#include <iostream>
using namespace std;

struct Node
{
    int coeff;
    int pow;
    struct Node *next;
    Node *prev;
};

void create_node(int x, int y, struct Node **temp)
{
    struct Node *r, *z;
    z = *temp;
    if (z == NULL)
    {
        r = new Node;
        r->coeff = x;
        r->pow = y;
        *temp = r;
        r->next = new Node;
        r = r->next;
        r->next = NULL;
    }
    else
    {
        r->coeff = x;
        r->pow = y;
        r->next = new Node;
        r = r->next;
        r->next = NULL;
    }
}

void polyadd(struct Node *poly1, struct Node *poly2,
             struct Node *poly)
{
    while (poly1->next && poly2->next)
    {
        if (poly1->pow > poly2->pow)
        {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff;
            poly1 = poly1->next;
        }

        else if (poly1->pow < poly2->pow)
        {
            poly->pow = poly2->pow;
            poly->coeff = poly2->coeff;
            poly2 = poly2->next;
        }

        else
        {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff + poly2->coeff;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        
        poly->next = new Node;
        poly = poly->next;
        poly->next = NULL;
    }
    while (poly1->next || poly2->next)
    {
        if (poly1->next)
        {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        if (poly2->next)
        {
            poly->pow = poly2->pow;
            poly->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        poly->next = new Node;
        poly = poly->next;
        poly->next = NULL;
    }
}

void show(struct Node *node)
{
    while (node->next != NULL)
    {
        cout<<node->coeff<<"x^"<<node->pow<<" ";
        node = node->next;
        if (node->coeff >= 0)
        {
            if (node->next != NULL)
                cout<<"+"<<" ";
        }
    }
}

int main()
{
    struct Node *poly1 = NULL, *poly2 = NULL, *poly = NULL;
int length;
int degree,coeff;

    cout<<"Enter the length of first polynomial: ";
    cin>>length;
    
    for(int i=0;i<length;i++)
    {
    	cout<<"Enter coeff: ";
    	cin>>coeff;
    	cout<<"Enter degree: ";
    	cin>>degree;
    	create_node(coeff,degree,&poly1);
	}
    
    cout<<"\nEnter the length of second polynomial: ";
    cin>>length;
    
    for(int i=0;i<length;i++)
    {
    	cout<<"Enter coeff: ";
    	cin>>coeff;
    	cout<<"Enter degree: ";
    	cin>>degree;
    	create_node(coeff,degree,&poly2);
	}

    cout<<"\n1st Polynomial: ";
    show(poly1);

    cout<<"\n2nd Polynomial: ";
    show(poly2);

    poly = new Node;

    polyadd(poly1, poly2, poly);

    cout<<("\nAdded polynomial: ");
    show(poly);

    return 0;
}
