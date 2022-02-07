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
    bool isTrue = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] == 1)
            isTrue = 1;
    }
    if (isTrue)
        cout << "Hard\n";
    else
        cout << "EASY\n";
    return 0;
}