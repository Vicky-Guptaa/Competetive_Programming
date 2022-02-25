#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    int answer[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        answer[arr[i] - 1] = i + 1;
    }
    for (auto x : answer)
        cout << x << " ";
    cout << "\n";
    return 0;
}