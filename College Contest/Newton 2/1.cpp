#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;

int main()
{

    int t, k;
    cin >> t;
    k = t;

    int arr[2010] = {0};
    int answer = 0, cmin = 1e9;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        for (int i = a; i <= b; i++)
        {
            arr[i] += 1;
            answer = max(answer, arr[i]);
        }
        cmin = min(c, cmin);
    }
    int res = 0;
    for (int i = 1; i < 2010; i++)
    {
        if (answer == arr[i])
            res++;
    }
    if (cmin < res)
        cout << cmin << "\n";
    else
        cout << res << "\n";
    return 0;
}