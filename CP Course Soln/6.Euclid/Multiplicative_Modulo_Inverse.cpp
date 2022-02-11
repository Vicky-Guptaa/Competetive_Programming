#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

vector<int> Extended_Eulid(int a, int b)
{
    if (b == 0)
        return {1, 0, a};
    vector<int> result = Extended_Eulid(b, a % b);
    int smallX = result[0];
    int smallY = result[1];
    int gcd = result[2];
    int currX = smallY;
    int currY = smallX - (a / b) * smallY;
    return {currX, currY, gcd};
}

int Multiplicative_Modulo_Inverse(int a, int m)
{
    vector<int> result = Extended_Eulid(a, m);
    int x = result[0];
    int gcd = result[2];
    if (gcd != 1)
    {
        cout << "MMI Not Exist\n";
        return -1;
    }
    int ans = (x % m + m) % m; // x can be negative so we make it positve
    return ans;
}

int main()
{
    int a, m;
    cin >> a >> m;
    cout << Multiplicative_Modulo_Inverse(a, m) << "\n";
    return 0;
}