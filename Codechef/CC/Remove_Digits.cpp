#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, d;
        cin >> n >> d;
        int p = -1, temp = n, i = 0;
        int ans = 0, val = 0;
        while (temp > 0)
        {
            if (temp % 10 == d)
            {
                p = i;
            }
            temp /= 10;
            i++;
        }
        if (p == -1)
        {
            cout << 0 << endl;
            continue;
        }

        if (d == 0)
        {
            int nnum = n;
        A:
            val = pow(10, p);
            int b = pow(10, p + 1);
            int a = (nnum % b);
            nnum += val - a;
            temp = nnum;
            i = 0;
            p = -1;
            while (temp > 0)
            {
                if (temp % 10 == d)
                {
                    p = i;
                }
                temp /= 10;
                i++;
            }
            if (p == -1)
                cout << nnum - n << endl;
            else
                goto A;
            continue;
        }
        else
        {
            if (d < 9)
            {
                val += (d + 1) * pow(10, p);
                int b = pow(10, p + 1);
                int a = (n % b);
                cout << val - a << endl;
            }
            else
            {
                int nnum = n;
            B:
                val = pow(10, p);
                int b = pow(10, p);
                int a = (nnum % b);
                nnum += val - a;
                temp = nnum;
                i = 0;
                p = -1;
                while (temp > 0)
                {
                    if (temp % 10 == d)
                    {
                        p = i;
                    }
                    temp /= 10;
                    i++;
                }
                if (p == -1)
                    cout << nnum - n << endl;
                else
                    goto B;
            }
        }
    }
    return 0;
}
// 3289 9