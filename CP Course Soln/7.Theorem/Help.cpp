#include <iostream>
#include <string.h>
using namespace std;

struct node *head = nullptr;
struct node *tail = nullptr;
struct node
{
    char n[4];
    int pr;
    int brs;
    int comple_time = 0;
    struct node *next;
};
void insert()
{
    int s;
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == nullptr)
    {
        cout << "No memory present" << endl;
        return;
    }
    else
    {
        s++;
        cout << "Enter your priority" << endl;
        int p;
        cin >> p;
        fflush(stdin);
        cout << "Enter your process" << endl;
        char n[20];
        gets(n);
        cout << "Enter your brust time" << endl;
        int brs;
        cin >> brs;
        ptr->pr = p;
        strcpy(ptr->n, n);
        ptr->brs = brs;
        ptr->next = nullptr;
        struct node *temp = head;
        if (head == nullptr)
        {
            head = ptr;
            tail = ptr;
        }
        else
        {
            if (temp->pr > ptr->pr)
            {
                ptr->next = head;
                head = ptr;
            }
            else if (tail->pr <= ptr->pr)
            {
                tail->next = ptr;
                tail = tail->next;
            }
            else
            {
                while (temp)
                {
                    if (temp->next->pr > ptr->pr)
                    {
                        ptr->next = temp->next;
                        temp->next = ptr;
                        break;
                    }
                    temp = temp->next;
                }
            }
        }
    }

    ptr->comple_time = ptr->pr + ptr->brs;
    if (ptr->next != nullptr && ptr->brs >= ptr->next->pr)
    {
        ptr->comple_time += ptr->next->brs;
    }
    else
    {
        ptr->pr += 1;
    }
}
void display(struct node *head)
{

    cout << "PROCESS NAME | "
         << "ARRIVAL TIME | "
         << "BRUST TIME | "
         << " | "
         << "COMPLETION TIME" << endl;
    while (head != nullptr)
    {

        cout << head->n << " | " << head->pr << " | " << head->brs << " | " << head->comple_time << endl;
        head = head->next;
    }
}
int main()
{

    int ch = 0;
    while (ch != 5)
    {
        cout << "\n1. INSERT \n2. EXECUTE \n3. display \n4 TOTAL OPERATIONS \n5.EXIT IT" << endl;
        cout << "Enter your choice" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            insert();
            display(head);
            break;
        case 2:
            display(head);
            break;
        case 3:
            break;
        }
    }
    return 0;
}