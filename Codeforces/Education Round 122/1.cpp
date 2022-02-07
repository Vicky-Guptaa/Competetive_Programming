#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr;
        int temp = n;
        if (n % 7 == 0)
        {
            cout << n << "\n";
        }
        else
        {
            while (n > 0)
            {
                arr.push_back(n % 10);
                n /= 10;
            }
            for (int i = 0; i < arr.size(); i++)
            {
                vector<int> tm = arr;
                for (int j = 0; j <= 9; j++)
                {
                    if (i == arr.size() - 1 && j == 0)
                    {
                        continue;
                    }
                    tm[i] = j;
                    int newnum = 0;
                    int pow = 1;
                    for (int k = 0; k < tm.size(); k++)
                    {
                        newnum += tm[k] * pow;
                        pow *= 10;
                    }
                    if (newnum % 7 == 0)
                    {
                        n = newnum;
                        break;
                    }
                }
                if (n != 0)
                {
                    break;
                }
            }
            cout << n << "\n";
        }
    }
    return 0;
}