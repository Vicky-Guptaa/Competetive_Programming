#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int arr[4];
        for (int i = 0; i < 4; i++)
        {
            cin >> arr[i];
        }

        int rem = arr[0] % arr[1];

        int dincrement = arr[0] / arr[1];
         
        long long int sum = (dincrement*(2*arr[2]+(dincrement-1)*arr[3])/2)*arr[1];
        sum+=(arr[2]+(dincrement)*arr[3])*rem;
        cout << sum << endl;
    }
    return 0;
}
