#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

vector<ll> Extended_Euclid(ll a, ll b)
{
    if (b == 0)
        return {1, 0, a};
    vector<ll> result = Extended_Euclid(b, a % b);
    int smallX = result[0], smallY = result[1], gcd = result[2];
    int currX = smallY, currY = smallX - (a / b) * smallY;
    return {currX, currY, gcd};
}

void Linear_Diophantine(ll n, ll p, ll w, ll d)
{
    vector<ll> result = Extended_Euclid(w, d);
    int x_ = result[0], y_ = result[1], gcd = result[2];
    if (p % gcd != 0)
    {
        cout << "-1\n";
        return;
    }
    ll k = p / gcd;
    ll Xo = x_ * k;
    ll Yo = y_ * k;
    ll Zo = n - Xo - Yo;
    cout << Xo << " " << Yo << " " << Zo << "\n";
}

int main()
{
    ll n, p, w, d;
    cin >> n >> p >> d >> w;
    Linear_Diophantine(n, p, w, d);
    return 0;
}