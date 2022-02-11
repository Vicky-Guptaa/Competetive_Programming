#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll HCF(ll num1, ll num2)
{
    while (num2 != 0)
    {
        ll rem = num1 % num2;
        num1 = num2;
        num2 = rem;
    }
    return num1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        ll answer1 = arr[0], answer2 = arr[1];
        for (int i = 2; i < n; i++)
        {
            if (i % 2 == 0)
                answer1 = HCF(answer1, arr[i]);
            else
                answer2 = HCF(answer2, arr[i]);
        }
        if (answer1 == answer2)
        {
            cout << 0 << "\n";
        }
        else
        {
            if (answer1 == 1)
            {
                bool check = false;
                for (int i = 0; i < n; i += 2)
                {
                    if (arr[i] % answer2 == 0)
                    {
                        check = true;
                        break;
                    }
                }
                if (check)
                    cout << "0\n";
                else
                {
                    cout << answer2 << "\n";
                }
            }
            else if (answer2 == 1)
            {
                bool check = false;
                for (int i = 1; i < n; i += 2)
                {
                    if (arr[i] % answer1 == 0)
                    {
                        check = true;
                        break;
                    }
                }
                if (check)
                    cout << "0\n";
                else
                {
                    cout << answer1 << "\n";
                }
            }
            else
            {

                bool check = true;
                for (int i = 0; i < n; i += 2)
                {
                    if (arr[i] % answer2 == 0)
                    {
                        check = false;
                        break;
                    }
                }
                if (check)
                {
                    cout << answer2 << "\n";
                    continue;
                }
                check = true;
                for (int i = 1; i < n; i += 2)
                {
                    if (arr[i] % answer1 == 0)
                    {
                        check = false;
                        break;
                    }
                }
                if (check)
                {
                    cout << answer1 << "\n";
                    continue;
                }
                cout << "0\n";
            }
        }
    }
    return 0;
}
/*
10
10 15 20 3 25 6 30 9 35 21
*/