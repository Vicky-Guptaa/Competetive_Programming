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
    int answer = 1;
    for (auto &x : arr)
    {
        cin >> x;
    }
    int Max = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] < arr[i])
            answer++;
        else
            answer = 1;
        Max = max(answer, Max);
    }
    cout << Max << "\n";
    return 0;
}