#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long ll;

bool solve(int arr[], ll s, ll n, ll d)
{
    queue<pair<bool, pair<int, int>>> que;

    que.push({1, {0, s}});
    que.push({0, {0, s + 3}});
    bool isWho = 1;
    while (!que.empty())
    {
        bool isAlice = que.front().first;
        int index = que.front().second.first;
        int oper = que.front().second.second;
        int oper1 = oper + arr[index];
        int oper2 = (oper ^ arr[index]);
        que.pop();
        if (oper1 == d || oper2 == d)
        {
            if (index != n - 1)
            {
                return !isAlice;
            }
            isWho = isAlice;
        }
        if (index + 1 != n)
        {
            que.push({isAlice, {index + 1, oper1}});
            que.push({isAlice, {index + 1, oper2}});
        }
    }
    return isWho;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, s, d;
        cin >> n >> s >> d;
        int arr[n];
        ll oc = 0;
        for (auto &x : arr)
        {
            cin >> x;
            if (x & 1)
                oc++;
        }
        if (oc & 1)
        {
            if ((d & 1) != (s & 1))
            {
                cout << "Alice\n";
            }
            else
            {
                cout << "Bob\n";
            }
        }
        else
        {
            if ((d & 1) == (s & 1))
            {
                cout << "Alice\n";
            }
            else
            {
                cout << "Bob\n";
            }
        }
    }
    return 0;
}