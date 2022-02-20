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
    int temp = n;
    ll answer = temp;
    while (temp-- > 1)
    {
        int left = n - temp;
        answer += left * temp;
    }
    cout << answer << "\n";
    return 0;
}