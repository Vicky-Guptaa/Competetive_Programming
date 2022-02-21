#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    int n, t;
    cin >> n >> t;
    int arr[n - 1];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> arr[i];
    }
    bool isVisited = false;
    int i = 0;
    while (i < n - 1)
    {
        if (i + 1 + arr[i] == t)
        {
            isVisited = true;
            break;
        }
        i += arr[i];
    }
    if (isVisited)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}