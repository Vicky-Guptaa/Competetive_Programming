#include <bits/stdc++.h>
using namespace std;

template <class T>
struct Node
{
    T data;
    struct Node *next;
    struct Node *prev;
};
Node<int> *head = NULL, *p, *ptr, *rear = NULL, *temp;
vector<int> position;

template <class T>
void create_node(T x)
{
    ptr = new Node<T>;
    if (ptr == NULL)
    {
        cout << "\nMemory could not be allocated!\n";
        return;
    }
    ptr->data = x;
    ptr->next = NULL;
    ptr->prev = NULL;
}

int tot()
{
    int count = 1;
    if (head == NULL)
        return 0;
    else if (head->next == head)
        return 1;
    p = head->next;
    while (p != head)
    {
        p = p->next;
        count++;
    }
    return count;
}

void display()
{
    if (tot() == 0)
    {
        cout << "\nList empty!\n";
        return;
    }
    p = head;
    cout << "\n|| -> ";
    do
    {
        if (p->next == head)
            cout << p->data << " ";
        else
            cout << p->data << " <-> ";
        p = p->next;
    } while (p != head);
    cout << "<- ||" << endl;
}

void display_rev()
{
    if (tot() == 0)
    {
        cout << "\nList empty!\n";
        return;
    }
    p = rear;
    cout << endl
         << "NULL <- ";
    do
    {
        cout << p->data << " <-> ";
        p = p->prev;
    } while (p != head);
    cout << head->data;
    cout << " -> NULL" << endl;
}

template <class T>
void insert(T n, int pos, int flag = 0)
{
    create_node(n);
    if (tot() == 0)
    {
        head = ptr;
        rear = ptr;
        head->prev = head;
        head->next = head;
    }
    else if (pos == 1)
    {
        rear->next = ptr;
        ptr->prev = rear;
        head->prev = ptr;
        ptr->next = head;
        head = head->prev;

        // p = head;
        // while (p->next != head)
        //     p = p->next;
        // p->next = ptr;
        // ptr->prev = p;
        // head->prev = ptr;
        // ptr->next = head;
        // head = ptr;
    }
    else if (pos == tot())
    {
        // ptr->prev = head->prev;
        ptr->prev = rear;
        rear->next = ptr;
        rear = ptr;
        head->prev = rear;
        rear->next = head;
    }
    else
    {
        p = head;
        pos--;
        while (--pos)
            p = p->next;
        ptr->next = p->next;
        ptr->prev = p;
        p->next = ptr;
        // if (p->next != head)
        p->next->next->prev = ptr;
    }
    if (flag)
        return;
    display();
}

void del_ele(int pos)
{
    if (tot() == 0)
    {
        cout << "\nList empty!\n";
        return;
    }
    if (pos > tot())
    {
        cout << "\nInvalid position!\n";
        return;
    }
    else if (tot() == 1)
    {
        ptr = head;
        head = rear = NULL;
    }
    else if (pos == 1)
    {
        ptr = head;
        cout << "\nDeleting element: " << ptr->data << endl;
        head = head->next;
        head->prev = NULL;
    }
    else if (pos == tot())
    {
        ptr = head;
        while (ptr->next != rear)
            ptr = ptr->next;
        rear = ptr;
        ptr = ptr->next;
        cout << "\nDeleting element: " << ptr->data << endl;
        rear->next = NULL;
    }
    else
    {
        ptr = head;
        pos--;
        while (pos-- && ptr != NULL)
            ptr = ptr->next;
        ptr->prev->next = ptr->next;
        // if (ptr->next != NULL)
        ptr->next->prev = ptr->prev;
        cout << "\nDeleting element: " << ptr->data << endl;
    }
    delete ptr;
    display();
}

template <class T>
void search(T key, bool flag = false)
{
    if (tot() == 0)
    {
        cout << "\nList empty!\n";
        return;
    }
    position.clear();
    int k = 0;
    if (!flag)
        display();
    p = head;
    while (p != NULL)
    {
        k++;
        if (p->data == key)
            position.push_back(k);
        p = p->next;
    }
}

// sorted reqd
template <class T>
void search_del(T key)
{
    if (tot() == 0)
    {
        cout << "\nList empty!\n";
        return;
    }
    int k;
    search<int>(key);
X:
    cout << "\nEnter the number of elements you want to delete (out of " << position.size() << "): " << endl;
    cin >> k;
    if (k > position.size())
    {
        cout << "\nEnter valid number!\n";
        goto X;
    }
    else
    {
        while (k)
        {
            auto itr = position.begin();
            for (; itr != position.end(), k > 0; itr++, k--)
            {
                search<int>(key, true);
                itr = position.begin();
                del_ele(*itr);
            }
        }
        // cout<<"\nDeleting first occurrence of "<<key<<" at position "<<pos[0]<<endl;
        // del_pos(pos[0]);
    }
}

template <class T>
void swap(Node<int> *p, Node<int> *q)
{
    T tempo;
    tempo = q->data;
    q->data = p->data;
    p->data = tempo;
}

// Bubble sort O(n^2)
template <class T>
void sort_list(char c)
{
    if (tot() == 0)
    {
        cout << "\nList empty!\n";
        return;
    }
    temp = head;
    p = NULL;
    while (temp != NULL)
    {
        p = temp->next;
        while (p != NULL)
        {
            if (c == 'a' || c == 'A')
            {
                if (p->data < temp->data)
                    swap<int>(p, temp);
            }
            else if (c == 'd' || c == 'D')
            {
                if (p->data > temp->data)
                    swap<int>(p, temp);
            }
            p = p->next;
        }
        temp = temp->next;
    }
}

template <class T>
void insert_sorted(T n, char c)
{
    create_node(n);
    if (tot() == 0)
    {
        head = ptr;
        rear = ptr;
        display();
        return;
    }
    sort_list<int>(c);
    p = head;
    while (p != NULL)
    {
        if ((n <= head->data && (c == 'a' || c == 'A')) || (n >= head->data && (c == 'd' || c == 'D')))
        {
            insert(n, 1);
            return;
        }
        else if ((n >= rear->data && (c == 'a' || c == 'A')) || (n <= rear->data && (c == 'd' || c == 'D')))
        {
            insert(n, tot() + 1);
            return;
        }
        else if ((n > p->data && n <= p->next->data) || (n < p->data && n >= p->next->data))
        {
            ptr->next = p->next;
            p->next->prev = ptr;
            p->next = ptr;
            ptr->prev = p;
            break;
        }
        p = p->next;
    }
    display();
}

template <class T>
void insert_list(vector<T> list, int pos)
{
    for (auto x : list)
    {
        insert(x, pos, 1);
        pos++;
    }
}

long sum()
{
    long s = 0;
    if (tot() == 0)
        return s;
    p = head;
    while (p != NULL)
    {
        s += p->data;
        p = p->next;
    }
    return s;
}

template <class T>
T max_ele()
{
    T mx = head->data;
    p = head->next;
    while (p != NULL)
    {
        if (p->data > mx)
            mx = p->data;
        p = p->next;
    }
    return mx;
}

template <class T>
T min_ele(Node<T> *p)
{
    if (p == NULL)
        return head->data;
    T mn = min_ele<T>(p->next);
    return (mn < p->data) ? mn : p->data;
}

bool isSorted_asc()
{
    p = head;
    while (p->next != NULL)
    {
        if (p->data > p->next->data)
            return false;
        p = p->next;
    }
    return true;
}

bool isSorted_desc()
{
    p = head;
    while (p->next != NULL)
    {
        if (p->data < p->next->data)
            return false;
        p = p->next;
    }
    return true;
}

// sorted only
template <class T>
void del_duplicates()
{
    if (tot() == 0)
    {
        cout << "\nList empty!\n";
        return;
    }
    sort_list<int>('a');
    p = head;
    temp = head->next;
    while (temp != NULL)
    {
        if (p->data != temp->data)
        {
            // sliding
            p = temp;
            temp = temp->next;
        }
        else
        {
            p->next = temp->next;
            delete temp;
            temp = p->next;
        }
    }
    cout << "\nAfter removing all duplicates from list: " << endl;
    display();
}

void reverse_list()
{
    if (tot() == 0)
    {
        cout << "\nList empty!\n";
        return;
    }
    p = ptr = head;
    while (p != NULL)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        // since links already modified
        p = p->prev;
        if (p != NULL && p->next == NULL)
            head = p;
    }
    rear = ptr;
    display();
}

int main()
{
    int ch, n, k, key, num;
    char c;
    vector<int> list;
    while (1)
    {
    A:
        bool flag = false;
        cout << "\nMENU:\n1. Insert at beginning\n2. Insert at end\n3. Insert at given position\n4. Insert in a sorted list\n5. Insert a set of values\n6. Deletion from beginning\n7. Deletion from end\n8. Deletion from given position\n9. Reverse list\n10. Total number of elements\n11. Sum of elements of list\n12. Search item\n13. Search and delete\n14. Maximum and Minimum element in list\n15. isSorted\n16. Sort\n17. Remove all duplicates\n18. Display\n19. Display reverse\n20. Exit\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\nEnter the element to be inserted: ";
            cin >> n;
            insert(n, 1);
            break;
        case 2:
            cout << "\nEnter the element to be inserted: ";
            cin >> n;
            insert(n, tot());
            break;
        case 3:
            cout << "\nEnter the element to be inserted: ";
            cin >> n;
        C:
            cout << "\nEnter the position to be inserted: ";
            cin >> k;
            if (k <= 0)
            {
                cout << "\nEnter valid position!\n";
                goto C;
            }
            insert(n, k);
            break;
        case 4:
            cout << "\nEnter the element to be inserted: ";
            cin >> n;
            cout << "\nEnter the order of sorting (a for ascending, d for descending): ";
            cin >> c;
            insert_sorted(n, c);
            // display();
            break;
        case 5:
            cout << "\nEnter the number of elements initially: ";
            cin >> n;
            list.clear();
            cout << "\nEnter the position to be inserted: ";
            cin >> k;
            cout << "\nEnter the list of elements" << endl;
            while (n--)
            {
                cin >> num;
                list.push_back(num);
            }
            insert_list(list, k);
            display();
            break;
        case 6:
            del_ele(1);
            break;
        case 7:
            del_ele(tot());
            break;
        case 8:
        B:
            cout << "\nEnter the position to be deleted: ";
            cin >> k;
            if (k <= 0)
            {
                cout << "\nEnter valid position!\n";
                goto B;
            }
            del_ele(k);
            break;
        case 9: // reverse_list(NULL, head);
            //         display();
            reverse_list();
            break;
        case 10:
            cout << "\nTotal number of elements in list is: " << tot() << endl;
            break;
        case 11:
            if (tot() == 0)
                cout << "\nList empty! Sum : 0\n";
            else
                cout << "\nSum of all elements of the list is: " << sum() << endl;
            break;
        case 12:
            cout << "\nEnter the element to be searched for: ";
            cin >> key;
            search<int>(key);
            if (position.empty())
                cout << "\nElement not found in list!" << endl;
            else
            {
                for (auto x : position)
                    cout << "\nElement found at position " << x << " !" << endl;
            }
            break;
        case 13:
            cout << "\nEnter the element to be searched for: ";
            cin >> key;
            search_del<int>(key);
            break;
        case 14:
            if (tot() == 0)
                cout << "\nList empty!\n";
            else
            {
                cout << "\nMaximum element in the list is: " << max_ele<int>() << endl;
                cout << "\nMinimum element in the list is: " << min_ele<int>(head) << endl;
            }
            break;
        case 15:
            if (tot() == 0)
                cout << "\nList empty!\n";
            else
            {
                if (isSorted_asc())
                    cout << "\nThe list is sorted in ascending manner...\n";
                else
                    cout << "\nThe list is not sorted in ascending manner...\n";
                if (isSorted_desc())
                    cout << "\nThe list is sorted in descending manner...\n";
                else
                    cout << "\nThe list is not sorted in descending manner...\n";
            }
            break;
        case 16:
        D:
            cout << "\nEnter sorting order (a for ascending, d for descending): ";
            cin >> c;
            if (!(c == 'a' || c == 'A' || c == 'd' || c == 'D'))
            {
                cout << "\nEnter valid order choice!\n";
                goto D;
            }
            sort_list<int>(c);
            display();
            break;
        case 17:
            del_duplicates<int>();
            break;
        case 18:
            display();
            break;
        case 19:
            display_rev();
            cout << endl;
            break;
        case 20:
            exit(0);
        default:
            cout << "\nWrong choice! Enter again...\n";
            goto A;
        }
    }
    return 0;
}