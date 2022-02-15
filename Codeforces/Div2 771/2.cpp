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
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int prevo = -1, preve = 0;
        bool isSort = 1;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] & 1)
            {
                if (prevo > arr[j])
                {
                    isSort = 0;
                    break;
                }
                prevo = arr[j];
            }
            else
            {
                if (preve > arr[j])
                {
                    isSort = 0;
                    break;
                }
                preve = arr[j];
            }
        }
        if (isSort)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}