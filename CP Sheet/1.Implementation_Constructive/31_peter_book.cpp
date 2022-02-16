#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    int page;
    cin >> page;
    int arr[7];
    int sum = 0;
    for (int i = 0; i < 7; i++)
    {
        cin >> arr[i];
    }
    int res = 0;
    while (page > 0)
        for (int i = 0; i < 7; i++)
        {
            page -= arr[i];
            if (page <= 0)
            {
                res = i + 1;
                break;
            }
        }
    cout << res << "\n";
    return 0;
}