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
        long long N, V;
        cin >> N >> V;
        long long Max_Pet = N * (N - 1) / 2, Min = 0;
        if (N > V)
        {
            long long Travel = N - 1;
            long long Time = Travel / V;
            long long Rem = (Travel % V);
            long long left = N - V;
            left = left * (left + 1) / 2 - 1;
            Min += V + left;
            cout << Max_Pet << " " << Min << endl;
        }
        else
        {
            Min=(N-1);
            cout << Max_Pet << " " << Min << endl;
        }
    }
    return 0;
}