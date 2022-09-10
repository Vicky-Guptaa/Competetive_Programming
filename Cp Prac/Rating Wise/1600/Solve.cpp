#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int minAdjacentSwaps(int n, vector<char> &crr, vector<char> &arr)
{
    vector<int> index;
    for (int i = 0; i < n; i++)
    {
        if (crr[i] == arr[0] || crr[i] == arr[1])
        {
            index.push_back(i);
        }
    }
    ll oper = 0;
    string news;
    for (int i = 1; i < index.size(); i++)
    {
        news += crr[index[i - 1]];
        oper += index[i] - index[i - 1] - 1;
    }
    news += crr[index.back()];
    vector<int> a1, a2;
    for (int i = 0; i < news.size(); i++)
    {
        if (news[i] == arr[0])
        {
            a1.push_back(i);
        }
        if (news[i] == arr[1])
        {
            a2.push_back(i);
        }
    }

    for (int i = 1; i < a1.size(); i++)
    {
        oper += a1[i] - a1[i - 1] - 1;
    }
    for (int i = 1; i < a2.size(); i++)
    {
        oper += a2[i] - a2[i - 1] - 1;
    }
    return oper;
}

int main()
{
    int n;
    cin >> n;
    vector<char> crr(n);
    for (auto &x : crr)
        cin >> x;
    vector<char> arr(2);
    cin >> arr[0] >> arr[1];
    cout << minAdjacentSwaps(n, crr, arr);
    return 0;
}