#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    if (n1 == n2)
    {
        cout << "0\n";
    }
    else if (n2 % n1 != 0)
    {
        cout << -1 << "\n";
    }
    else
    {
        int div = n2 / n1;
        int count = 0;
        while (div % 2 == 0 || div % 3 == 0)
        {
            if (div % 2 == 0)
            {
                div /= 2;
            }
            else if (div % 3 == 0)
            {
                div /= 3;
            }
            else
                break;
            count++;
        }
        if (div != 1)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << count << "\n";
        }
    }
    return 0;
}