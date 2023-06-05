#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

vector<int> Extended_Gcd(int a, int b)
{
    if (b == 0) // x,y
        return {1, 0};
    vector<int> result = Extended_Gcd(b, a % b);
    int smallX = result[0];
    int smallY = result[1];

    int x = smallY;
    int y = smallX - (a / b) * smallY;
    return {x, y};
}

int main()
{
    int a, b;
    cin >> a >> b;
    // ax + by = gcd(a,b)
    vector<int> result = Extended_Gcd(a, b);
    cout << result[0] << " " << result[1] << '\n';
    return 0;
}