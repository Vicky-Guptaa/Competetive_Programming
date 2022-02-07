#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    int overallD = l * k;
    int noTaost = overallD / nl;
    int lime = c * d;
    int salt = p / np;
    cout << min(noTaost, min(lime, salt)) / n << "\n";
    return 0;
}