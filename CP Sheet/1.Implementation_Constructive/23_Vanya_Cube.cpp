#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    int size = 1;
    while (n >= (size + 1) * size / 2)
    {
        n -= (size + 1) * size / 2;
        size++;
    }
    cout << size - 1 << "\n";
    return 0;
}