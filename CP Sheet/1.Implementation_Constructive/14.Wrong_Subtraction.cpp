#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    int t, k;
    cin >> t >> k;
    while (k--)
    {
        if (t % 10)
        {
            t--;
        }
        else
        {
            t /= 10;
        }
    }
    cout << t << "\n";
    return 0;
}