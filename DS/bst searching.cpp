#include <iostream>
using namespace std;

struct Node
{

    int data;

    Node *llink;

    Node *rlink;
};

Node *rootNode = NULL;

Node *insert(Node *root)
{

    Node *temp = new Node();

    char c;

    if (root == NULL)
    {

        cout << "Enter the value:" << endl;

        cin >> temp->data;

        temp->llink = NULL;

        temp->rlink = NULL;

        return temp;
    }

    cout << "Value of node is: " << root->data << endl;

    cout << "Enter L or R:" << endl;

    cin >> c;

    if (c == 'L')
    {

        root->llink = insert(root->llink);
    }

    else if (c == 'R')
    {

        root->rlink = insert(root->rlink);
    }

    else
    {

        cout << "Invalid" << endl;
    }
}

void search(Node *root, int x)
{

    if (root->data == x)
    {

        cout << "Found!" << endl;

        return;
    }

    if (root->llink == NULL && root->rlink == NULL)
    {

        cout << "Not found" << endl;

        return;
    }

    else if (x < root->data)
    {

        search(root->llink, x);
    }

    else
    {

        search(root->rlink, x);
    }
}

int main()
{

    int op;

    int inp;

    cout << "1. Insert" << endl;

    cout << "2. Search" << endl;

    cout << "3. End" << endl;

    do
    {

        cout << "Enter option" << endl;

        cin >> op;

        switch (op)
        {

        case 1:

            if (rootNode == NULL)
            {

                rootNode = insert(rootNode);
            }

            else
            {

                insert(rootNode);
            }

            break;

        case 2:

            cout << "Enter the search element:" << endl;

            cin >> inp;

            search(rootNode, inp);

            break;
        }

    } while (op != 3);

    return 0;
}