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
    int x = 0, y = 0;
    int temp = n / 7;
    bool isTrue = 0;
    for (int i = temp; i >= 0; i--)
    {
        int sum = n - i * 7;
        if (sum % 4 == 0)
        {
            x = sum / 4;
            y = i;
            isTrue = 1;
            break;
        }
    }
    if (isTrue)
    {
        string res;
        for (int i = 0; i < x; i++)
            res += "4";
        for (int i = 0; i < y; i++)
            res += "7";
        cout << res << "\n";
    }
    else
    {
        cout << "-1\n";
    }
    return 0;
}