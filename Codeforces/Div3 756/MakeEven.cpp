#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int odd_count = 0, even_count = 0;
        int temp = n;
        int power = log10(n);
        int ans = n / int(pow(10, power));
        while (temp)
        {
            if ((temp % 10) & 1)
                odd_count++;
            else
                even_count++;
            temp /= 10;
        }
        if (even_count == 0)
            cout << "-1"
                 << "\n";
        else if ((n % 10) % 2 == 0)
            cout << "0\n";
        else if (ans % 2 == 0)
            cout << "1" << endl;
        else
            cout << "2" << endl;
    }
    return 0;
}