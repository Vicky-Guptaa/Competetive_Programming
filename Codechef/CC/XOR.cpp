#include <iostream>
using namespace std;
long long int Maximum=0;
int Max(long long int n,long long int a,long long int b,long long int i)
{
    if (n == 0)
    {
        Maximum = max(Maximum, a * b);
        return 0;
    }
    if (n % 2 == 0)
    {
        Max(n / 2, a + 1 * i, b + 1 * i, i * 2);
    }
    else
    {
        Max(n / 2, a , b + 1 * i, i * 2);
        Max(n / 2, a + 1 * i, b , i * 2);
    }
    return Maximum;
}

int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        long long int n;
        cin>>n;

        long long int a = 0, b = 0, i = 1;
    
        cout << Max(n, a, b, i) << endl;
        Maximum=0;
    }

    return 0;
}