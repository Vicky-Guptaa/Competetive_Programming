#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long p, m;
        cin >> p >> m;
        priority_queue<long long> pq;
        pq.push(p);
        pq.push(m);
        int count = 0;
        while (pq.size() > 1)
        {
            long long a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            if (a + b < 4 || a == 0 || b == 0)
                break;
            if (a == b)
            {
                int incrs = a / 2;
                a = 0;
                b = 0;
                count += incrs;
            }
            else if (a - b == 1)
            {
                count += b / 2;
                a = 0;
                b = 0;
            }
            else
            {
                if (a - b == 2)
                {
                    a -= 3;
                    b -= 1;
                    count++;
                }
                else
                {
                    long long incrs = a - b;
                    incrs /= 3;
                    if (incrs > b)
                        incrs = b;
                    count += incrs;
                    a -= 3 * incrs;
                    b -= incrs;
                }
            }

            if (a > 0)
                pq.push(a);
            if (b > 0)
                pq.push(b);
        }
        cout << count << "\n";
    }
    return 0;
}