#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        string str;
        cin >> str;
        int ones = 0;
        set<int> maxset, minset;
        for (int i = 0; i < n; i++)
        {
            if (str[i] == '1')
            {
                ones++;
            }
        }
        if (ones == n)
        {
            for (int i = 0; i < n; i++)
            {
                cout << arr[i] << " ";
            }
            cout << "\n";
        }
        else
        {
            vector<int> answer(n, 0);
            int max_strt = n - ones + 1;
            int min_strt = 1;
            int x = max_strt;
            for (int i = 1; i < max_strt; i++)
                minset.insert(i);
            for (int i = max_strt; i <= n; i++)
                maxset.insert(i);

            for (int i = 0; i < n; i++)
            {
                if (str[i] == '1')
                {
                    if (arr[i] >= x)
                    {
                        answer[i] = arr[i];
                        maxset.erase(arr[i]);
                    }
                }
                else
                {
                    if (arr[i] < x)
                    {
                        answer[i] = arr[i];
                        minset.erase(arr[i]);
                    }
                }
            }
            for (int i = 0; i < n; i++)
            {
                if (answer[i] != 0)
                    continue;
                if (str[i] == '1')
                {

                    answer[i] = *maxset.begin();
                    maxset.erase(*maxset.begin());
                }
                else
                {

                    answer[i] = *minset.begin();
                    minset.erase(*minset.begin());
                }
            }
            for (auto x : answer)
                cout << x << " ";
            cout << "\n";
        }
    }
    return 0;
}
