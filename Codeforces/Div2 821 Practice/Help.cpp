#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <list>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <queue>

#define FOR(a, b, c) for (int a = b; a < c; a++)
#define ll long long int
#define pb push_back
#define pp pop_back
#define vi vector<int>
#define all(v) v.begin(), v.end()

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, x, y;
        cin >> n >> x >> y;

        // x>=y

        string a, b;
        cin >> a >> b;

        ll diff = 0;

        queue<int> ind;
        FOR(i, 0, n)
        {
            if (a[i] != b[i])
            {
                diff++;
                ind.push(i);
            }
        }
        if (diff & 1 == 1)
        {
            cout << "-1" << endl;
            continue;
        }
        if (diff > 2 || diff == 0)
        {
            cout << (diff / 2) * y << endl;
            // cout << "here we go 0";
            continue;
        }
        // cout << endl;
        // cout << "diff is " << diff << " and front and back are " << ind.front() << " and " << ind.back() << " respectively " << endl;
        if (diff == 2 && ind.front() == ind.back() - 1)
        {
            // most vulnerable case
            if (x > 2 * y)
            {
                if ((n - (ind.back() + 1)) >= 2 || ind.front() >= 2)
                {
                    cout << diff * y << endl;
                    // cout << "here we go 1";
                }
                else
                {
                    cout << (diff / 2) * x << endl;
                    // cout << "here we go 2";
                }
            }
            else
            {
                cout << (diff / 2) * x << endl;
                // cout << "here we go 3";
            }
        }
        else
        {
            // cout << "here we go 4";
            cout << (diff / 2) * y << endl;
        }
    }
    return 0;
}