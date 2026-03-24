#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int info;
    node *next;
    int ctr = 1;
};
class linkedlist
{
    node *head;
    node *tail;

public:
    linkedlist()
    {
        head = NULL;
        tail = NULL;
    }

    void addInOrder(int val)
    {
        if (head == NULL)
        {
            node *newnode = new node;
            newnode->info = val;
            newnode->next = NULL;
            head = tail = newnode;
        }
        else
        {
            if (val < head->info)
            {
                node *newnode = new node;
                newnode->info = val;
                newnode->next = head;
                head = newnode;
                return;
            }
            if (val > tail->info)
            {
                node *newnode = new node;
                newnode->info = val;
                newnode->next = NULL;
                tail->next = newnode;
                tail = newnode;
                return;
            }
            node *current = head;
            while (current != NULL)
            {
                if (current->info == val)
                {
                    current->ctr++;
                    return;
                }
                if (current->next != NULL && current->next->info > val)
                {
                    node *newnode = new node;
                    newnode->info = val;
                    newnode->next = current->next;
                    current->next = newnode;
                    return;
                }
                current = current->next;
            }
        }
    }
    void display()
    {
        node *outerloop = head;
        while (outerloop != NULL)
        {
            int innerloop = outerloop->ctr;
            while (innerloop > 0)
            {
                cout << outerloop->info << " ";
                innerloop--;
            }
            outerloop = outerloop->next;
        }
    }
    void deleteValue(int val)
    {
        if (head == NULL)
            return;

        if (val == head->info)
        {
            if (head->ctr > 1)
            {
                head->ctr--;
                return;
            }
            node *temp = head;
            if (head == tail)
            {
                head = tail = NULL;
            }
            else
            {
                head = head->next;
            }
            delete temp;
            return;
        }

        if (val == tail->info)
        {
            if (tail->ctr > 1)
            {
                tail->ctr--;
                return;
            }
            node *temp = head;
            while (temp->next != tail)
            {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = NULL;
            return;
        }

        node *prev = head;
        node *current = head->next;
        while (current != NULL)
        {
            if (val == current->info)
            {
                if (current->ctr > 1)
                {
                    current->ctr--;
                    return;
                }
                prev->next = current->next;
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }

        cout << "NOT FOUND !\n";
    }

    void displayDescending(node *head)
    {
        node *current = head;
        if (current == NULL)
            return;
        displayDescending(current->next);

        int counter = current->ctr;
        while (counter > 0)
        {
            cout << current->info << " ";
            counter--;
        }
    }
    void displayDescending()
    {
        displayDescending(head);
        cout << '\n';
    }
    int removeMax()
    {
        if (head == NULL)
        {
            cout << "EMPTY\n";
            return -1;
        }
        if (head == tail)
        {
            delete head;
            head = tail = NULL;
            return -1;
        }
        node *current = head;
        while (current->next != tail)
        {
            current = current->next;
        }
        int Max = tail->info;
        delete tail;
        tail = current;
        current->next = NULL;
        return Max;
    }
    void generateFromArray(int arr[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            addInOrder(arr[i]);
        }
    }
    void clear()
    {
        node *temp = head;
        while (temp != NULL)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
        tail = NULL;
    }
};
int main()
{
    linkedlist list;

    int myData[] = {10, 5, 8, 5, 10, 12};
    list.generateFromArray(myData, 6);

    cout << "Display: ";
    list.display();
    cout << endl;

    cout << "Descending: ";
    list.displayDescending();

    list.deleteValue(8);
    cout << "After delete 8: ";
    list.display();
    cout << endl;

    int maxVal = list.removeMax();
    cout << "Max removed: " << maxVal << endl;
    cout << "After removeMax: ";
    list.display();
    cout << endl;

    list.clear();
    cout << "List Cleared." << endl;

    return 0;
}
