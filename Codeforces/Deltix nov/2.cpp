#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int Find(string str, int s, int l)
{
    int count = 0;
    for (int i = s; i < l; i++)
    {
        if (i + 2 < l && str[i] == 'a' && str[i + 1] == 'b' && str[i + 2] == 'c')
        {
            count++;
            i += 2;
        }
    }
    return count;
}

int main()
{
    int n, m;
    cin >> n >> m;
    string str;
    cin >> str;
    int count = Find(str, 0, n);
    while (m--)
    {
        int k;
        cin >> k;
        char ch;
        cin >> ch;
        k--;
        if (str[k] == ch)
        {
            cout << count << "\n";
            continue;
        }
        int cnt1 = Find(str, max(0, k - 2), min(k + 3, n));
        str[k] = ch;
        cnt1 -= Find(str, max(0, k - 2), min(k + 3, n));
        count -= cnt1;
        cout << count << "\n";
    }
    return 0;
}