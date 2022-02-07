#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n = 5;
    int arr[] = {-2, 5, -6, -4, 11};
    int sum = 0, Max = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum <= 0)
            sum = 0;
        if (Max < sum)
            Max = sum;
    }
    cout << -Max << "\n";
    return 0;
}