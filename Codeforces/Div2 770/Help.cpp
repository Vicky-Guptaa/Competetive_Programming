#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

struct ListNode
{
    ListNode *next;
    int val;
    ListNode(int data = 0)
    {
        val = data;
        next = nullptr;
    }
};

ListNode *partition(ListNode *head, int x)
{
    ListNode *res = NULL;
    ListNode *curr1 = NULL;
    ListNode *curr = head;
    while (curr != NULL)
    {
        if (curr->val < x)
        {
            ListNode *temp = curr;
            if (res == NULL)
            {
                res = curr1 = temp;
            }
            else
            {
                curr1->next = temp;
                curr1 = temp;
            }
        }
        curr = curr->next;
    }
    ListNode *curr2 = head;
    while (curr2 != NULL)
    {
        if (curr2->val == x)
        {
            ListNode *temp2 = curr2;
            if (res == NULL)
            {
                res = curr1 = temp2;
            }
            else
            {
                curr1->next = temp2;
                curr1 = temp2;
            }
        }
        curr2 = curr2->next;
    }
    return res;
}

int main()
{

    return 0;
}