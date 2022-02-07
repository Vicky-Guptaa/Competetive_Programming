#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int count = 0;
        for (int i = 2; i <= n; i++)
        {
            for (int k = 1; k <= i / 2; k++)
            {
                 if(i%k!=0)continue;
                int no = (n - k) / i+1 ;
                count += no;
            }
        }
        cout << count << endl; // <<count <<endl;
    }
    return 0;
}

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         int count = 0;
//         for (int i = 1; i <= n; i++)
//         {
//             for (int j = 1; j <= n; j++)
//             {
//                 if (j % i != 0 && (i % (j % i)) == 0)
//                 {
//                     cout << "(" << j << "," << i << "," << j % i << ") ";
//                     count++;
//                 }
//             }
//         }
//         cout << count << endl;
//     }
//     return 0;
// }
