#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int counter = 0;
        for (int i = 1; i <= 9; i++)
        {
            int temp = 0, pow = 1;
            int cnt = 1;
            while (temp != n && pow < 10000)
            {
                counter += cnt++;
                temp += i * pow;
                pow *= 10;
            }
            if (temp == n)
                break;
        }
        cout << counter << "\n";
    }
    return 0;
}