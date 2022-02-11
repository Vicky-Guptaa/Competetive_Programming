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
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr1, arr2;
        for (int i = 0; i < 2 * n; i++)
        {
            int num;
            cin >> num;
            if (i < n)
                arr1.push_back(num);
            else
                arr2.push_back(num);
        }
        for (int i = 0; i < n; i++)
        {
            if (arr1[i] > arr2[i])
            {
                swap(arr1[i], arr2[i]);
            }
        }
        int m1 = *max_element(arr1.begin(), arr1.end());
        int m2 = *max_element(arr2.begin(), arr2.end());
        cout << m1 * m2 << "\n";
    }
    return 0;
}