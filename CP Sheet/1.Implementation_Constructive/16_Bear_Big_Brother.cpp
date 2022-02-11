#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    int a, b;
    cin >> a >> b;
    int year = 0;
    while (a <= b)
    {
        year++;
        a *= 3;
        b *= 2;
    }
    cout << year << "\n";
    return 0;
}