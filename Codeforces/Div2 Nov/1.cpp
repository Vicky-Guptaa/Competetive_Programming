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
        int x1, p1, x2, p2;
        cin >> x1 >> p1 >> x2 >> p2;
        string str1, str2;
        int tp1 = log10(x1), tp2 = log10(x2);
        if (x1 == 0 && x2 == 0)
        {
            cout << "=\n";
        }
        else if (x1 == 0)
        {
            cout << "<\n";
        }
        else if (x2 == 0)
        {
            cout << ">\n";
        }
        else
        {
            if (tp1 + p1 == tp2 + p2)
            {
                string str1 = to_string(x1), str2 = to_string(x2);
                if (tp1 > tp2)
                {
                    for (int i = 0; i < tp1 - tp2; i++)
                        str2 += "0";
                }
                else if (tp1 < tp2)
                {
                    for (int i = 0; i < tp2 - tp1; i++)
                        str1 += "0";
                }
                int n = str1.compare(str2);
                if (n == 0)
                    cout << "=\n";
                else if (n > 0)
                    cout << ">\n";
                else
                    cout << "<\n";
            }
            else if (tp1 + p1 > tp2 + p2)
            {
                cout << ">\n";
            }
            else
            {
                cout << "<\n";
            }
        }
    }
    return 0;
}