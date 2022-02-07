#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

vector<int> Extended_Euclid(int a, int b)
{
    if (b == 0)
        return {1, 0, a};
    vector<int> result = Extended_Euclid(b, a % b);
    int smallX = result[0], smallY = result[1], gcd = result[2];
    int currX = smallY, currY = smallX - (a / b) * smallY;
    return {currX, currY, gcd};
}

vector<int> Linear_Diophantine(int a, int b, int c)
{
    vector<int> result = Extended_Euclid(a, b);
    int x_ = result[0], y_ = result[1], gcd = result[2];
    if (c % gcd)
    {
        cout << "Not Exist Such Soln\n";
        return {-1, -1};
    }
    int k = c / gcd;
    return {k * x_, k * y_};
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> result = Linear_Diophantine(a, b, c);
    cout << "x->" << result[0] << " y->" << result[1] << "\n";
    return 0;
}