#include <iostream>

using namespace std;

class Node

{

public:
    int data;

    Node *next;

    Node *prev;
};

class DoublyLinkedList

{

private:
    Node *head, *tail;

public:
    DoublyLinkedList()

    {

        head = NULL;

        tail = NULL;
    }

    void Insert_End(int elem)

    {

        Node *temp = new Node;

        temp->data = elem;

        temp->next = NULL;

        if (head == NULL)

        {

            temp->prev = NULL;

            head = temp;
        }

        else

        {

            temp->prev = tail;

            tail->next = temp;
        }

        tail = temp;
    }

    void Delete_End()

    {

        Node *temp = new Node;

        temp = tail;

        if (temp->prev == NULL)

        {

            head = tail = NULL;

            delete temp;

            return;
        }

        temp->prev->next = NULL;

        tail = temp->prev;

        delete temp;

        return;
    }

    void insert_pos(int elem, int loc)

    {

        Node *temp = new Node;

        Node *temp2 = new Node;

        Node *trav;

        trav = head;

        temp->data = elem;

        if (loc == 0)

        {

            temp->next = head;

            head = temp;

            return;
        }

        int count = 0;

        if (trav == NULL)

        {

            Insert_End(elem);
        }

        while (trav != NULL)

        {

            if (count == loc)

            {

                break;
            }

            count++;

            trav = trav->next;
        }

        for (int i = 0; i < loc - 2; i++)

        {

            if (temp2 == NULL)

            {

                Insert_End(elem);

                break;
            }

            temp2 = temp2->next;
        }

        trav->prev->next = temp;

        temp->prev = trav->prev;

        temp->next = trav;

        trav->prev = temp;
    }

    void delete_pos(int loc)

    {

        Node *trav;

        trav = head;

        if (loc == 0)

        {

            head = trav->next;

            delete trav;

            return;
        }

        if (trav == NULL)

        {

            Delete_End();
        }

        int count = 0;

        while (trav != NULL)

        {

            if (count == loc)

            {

                break;
            }

            count++;

            trav = trav->next;
        }

        trav->prev->next = trav->next;

        trav->next->prev = trav->prev;
    }

    void insert_after(int elem, int val)

    {

        Node *temp = new Node;

        Node *trav = new Node;

        temp->data = elem;

        trav = head;

        bool found = false;

        while (trav != NULL)

        {

            if (val == trav->data)

            {

                found = true;

                if (trav->next != NULL)

                    trav->next->prev = temp;

                else

                    tail = temp;

                temp->next = trav->next;

                trav->next = temp;

                temp->prev = trav;

                break;
            }

            trav = trav->next;
        }

        if (!found)

        {

            cout << "Element not found" << endl;
        }
    }

    void insert_before(int elem, int val)

    {

        Node *temp = new Node;

        Node *trav = new Node;

        temp->data = elem;

        trav = tail;

        bool found = false;

        while (trav != NULL)

        {

            if (val == trav->data)

            {

                found = true;

                if (trav->prev != NULL)

                    trav->prev->next = temp;

                else

                    head = temp;

                temp->prev = trav->prev;

                trav->prev = temp;

                temp->next = trav;

                break;
            }

            trav = trav->prev;
        }

        if (!found)

        {

            cout << "Element not found" << endl;
        }
    }

    void display()

    {

        Node *trav = new Node;

        trav = head;

        while (trav != NULL)

        {

            cout << trav->data << ' ';

            trav = trav->next;
        }

        cout << endl;
    }
};

int main()

{

    DoublyLinkedList D;

    int option;

    int data;

    int loc, elem;

    cout << "1. Insert an element at the rear end of the list" << endl;

    cout << "2. Delete an element from the rear end of the list" << endl;

    cout << "3.Insert an element at a given index of the list" << endl;

    cout << "4. Delete an element from given index from the list" << endl;

    cout << "5. Insert an element after another element " << endl;

    cout << "6. Insert an element before another element " << endl;

    cout << "7. Print the list" << endl;

    cout << "8. Exit" << endl;

    while (1)

    {

        cout << "\nEnter a choice: ";

        cin >> option;

        switch (option)

        {

        case 1:

            cout << "Enter the element to insert at end :";

            cin >> elem;

            D.Insert_End(elem);

            break;

        case 2:

            D.Delete_End();

            break;

        case 3:

            cout << "Enter the index of the element to be inserted:";

            cin >> loc;

            cout << "Enter the element to insert:";

            cin >> elem;

            D.insert_pos(elem, loc);

            break;

        case 4:

            cout << "Enter the index of the element to be deleted: ";

            cin >> loc;

            D.delete_pos(loc);

            break;

        case 5:

            cout << "Enter the element after which insertion is to be done :";

            cin >> loc;

            cout << "Enter the element to insert:";

            cin >> elem;

            D.insert_after(elem, loc);

            break;

        case 6:

            cout << "Enter the element before which insertion is to be done :";

            cin >> loc;

            cout << "Enter the element to insert:";

            cin >> elem;

            D.insert_before(elem, loc);

            break;

        case 7:

            D.display();

            break;

        case 8:

            exit(0);

        default:

            cout << "Invalid Choice!" << endl;

            break;
        }
    }
}
