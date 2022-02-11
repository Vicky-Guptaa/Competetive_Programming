#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        if (k == n - 1)
        {
            if (n == 4)
                cout << "-1\n";
            else
            {
                unordered_set<int> uset;
                for (int i = 0; i < n; i++)
                    uset.insert(i);
                cout << 0 << " " << n / 2 << "\n";
                cout << 1 << " " << (n / 2) - 1 << "\n";
                cout << n - 2 << " " << n - 1 << "\n";
                uset.erase(0);
                uset.erase(n / 2);
                uset.erase(1);
                uset.erase(n / 2 - 1);
                uset.erase(n - 1);
                uset.erase(n - 2);

                while (!uset.empty())
                {
                    int num1 = *uset.begin();
                    int num2 = n - num1 - 1;
                    uset.erase(num1);
                    uset.erase(num2);
                    cout << num1 << " " << num2 << '\n';
                }
            }
        }
        else if (k == 0)
        {
            for (int i = 0; i < n / 2; i++)
            {
                cout << i << " " << n - i - 1 << "\n";
            }
        }
        else
        {
            unordered_set<int> uset;
            for (int i = 0; i < n; i++)
                uset.insert(i);
            uset.erase(0);
            uset.erase(n - k - 1);
            cout << 0 << " " << n - k - 1 << '\n';
            uset.erase(k);
            uset.erase(n - 1);
            cout << k << " " << n - 1 << '\n';
            while (!uset.empty())
            {
                int num1 = *uset.begin();
                int num2 = n - num1 - 1;
                uset.erase(num1);
                uset.erase(num2);
                cout << num1 << " " << num2 << '\n';
            }
        }
    }
    return 0;
}