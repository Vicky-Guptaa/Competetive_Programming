#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    int arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr, arr + 3);
    int min_ans = 1e9;
    for (int i = arr[0]; i <= arr[2]; i++)
    {
        min_ans = min(min_ans, abs(i - arr[0]) + abs(i - arr[1]) + abs(i - arr[2]));
    }
    cout << min_ans << "\n";
    return 0;
}