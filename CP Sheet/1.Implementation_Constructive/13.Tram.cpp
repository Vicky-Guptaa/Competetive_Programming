#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    int t;
    cin >> t;
    int Max = 0;
    int passenger = 0;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        passenger -= a;
        passenger += b;
        Max = max(Max, passenger);
    }
    cout << Max << "\n";
    return 0;
}