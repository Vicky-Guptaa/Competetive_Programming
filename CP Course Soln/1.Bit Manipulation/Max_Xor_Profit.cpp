#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long long l, r;
    cin >> l >> r;
    long long Xor = l ^ r;
    int msb = 0;
    while (Xor)
    {
        msb++;
        Xor = (Xor >> 1);
    }
    long long ans = (1ll << msb) - 1;
    cout << ans << "\n";
    return 0;
}