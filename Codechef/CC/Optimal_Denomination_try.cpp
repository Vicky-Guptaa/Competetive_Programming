#include <iostream>
#include <vector>
using namespace std;

int GCD(long long int n1,long long int n2)
{
    long long int temp;
    while (1)
    {
        temp = n1 % n2;
        if (temp == 0)
        {
            break;
        }
        n1 = n2;
        n2 = temp;
    }
    return n2;
}
long long int GcdCalc(vector<long long int> gcd, int n)
{
    long long int g=1;
    for (int i = 1; i < n; i++)
    {
        g=max(g,GCD(gcd[i-1],gcd[i]));
    }
    return g;
}

void Optimal_Denomination(long long int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        vector<long long int> gcd;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            else
                gcd.push_back(arr[j]);
        }
        
    }
}

int main()
{
    // int t;
    // cin>>t;
    // while(t--)
    // {
    //     int n;
    //     cin>>n;
    //     long long int sal[n];
    //     for( int i=0;i<n;i++)
    //     {
    //         cin>>sal[i];
    //     }
    //     GCD(sal,n);
    // }
    cout << GCD(15, 60) << endl;
    return 0;
}