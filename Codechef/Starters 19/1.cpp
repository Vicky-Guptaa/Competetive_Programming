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
        int odd = 1, even = 2;
        for (int i = 2; i <= n; i++)
        {
            arr.push_back(i);
        }
        arr.push_back(1);
        for (auto x : arr)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}