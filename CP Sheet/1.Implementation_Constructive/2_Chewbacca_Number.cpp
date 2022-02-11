#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    vector<int> arr;
    while (n)
    {
        arr.push_back(n % 10);
        n /= 10;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (i == arr.size() - 1 && arr[i] == 9)
        {
            continue;
        }
        if (arr[i] >= 5)
        {
            arr[i] = 9 - arr[i];
        }
    }
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        cout << arr[i];
    }
    cout << "\n";
    return 0;
}