#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    int n, m;
    cin >> n >> m;
    if (n < m)
    {
        cout << -1 << "\n";
    }
    else
    {
        int move = (n & 1) ? 1 : 0;
        move += n / 2;
        bool isTrue = 0;
        while (move != n)
        {
            if (move % m == 0)
            {
                isTrue;
                break;
            }
            move++;
        }
        if (move % m == 0 || isTrue)
        {
            cout << move << "\n";
        }
        else
        {
            cout << "-1\n";
        }
    }
    return 0;
}