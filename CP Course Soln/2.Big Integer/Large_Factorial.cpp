#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

void Product(vector<int> &arr, int n)
{
    int carry = 0;
    int len = arr.size();
    for (int i = 0; i < len; i++)
    {
        int res = arr[i] * n + carry;
        carry = res / 10;
        arr[i] = res % 10;
    }
    while (carry != 0)
    {
        arr.push_back(carry % 10);
        carry /= 10;
    }
}

vector<int> Large_Factorial(int n)
{
    vector<int> result(1, 1);
    if (n == 1)
        return result;
    for (int i = 2; i <= n; i++)
    {
        Product(result, i);
    }
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<int> res = Large_Factorial(n);
    for (auto x : res)
        cout << x;
    cout << "\n";
    return 0;
}