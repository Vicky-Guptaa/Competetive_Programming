#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r[5];
        for (int i = 0; i < 5; i++)
            cin >> r[i];

        int e = 0, i = 0, d = 0;

        for (int k = 0; k < 5; k++)
        {
            if (r[k] == 0)
                d++;
            else if (r[k] == 1)
                i++;
            else if (r[k] == 2)
                e++;
        }

        if (e > i)
            cout << "ENGLAND" << endl;
        else if (i > e)
            cout << "INDIA" << endl;
        else
            cout << "DRAW" << endl;
    }
    return 0;
}
