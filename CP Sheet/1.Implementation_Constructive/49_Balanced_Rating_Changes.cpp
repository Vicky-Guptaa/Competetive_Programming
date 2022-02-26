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
    int flip = 1;
    while (t--)
    {
        int num;
        cin >> num;
        if (num & 1)
        {
            if (flip)
                cout << (num + flip) / 2 << "\n";
            else
                cout << (num + flip) / 2 << "\n";
            flip *= -1;
        }
        else
            cout << num / 2 << "\n";
    }
    return 0;
}