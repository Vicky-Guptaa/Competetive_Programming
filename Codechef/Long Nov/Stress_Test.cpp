#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int func1(long long arr[], int n)
{
    long long power2 = 1;
    long long ans = 0;
    bool notfound = false;
    for (int i = 0; i < 64; i++)
    {
        long long Xor = 0;
        for (int i = 0; i < n; i++)
            Xor ^= arr[i];
        if (i == 63 && (Xor & power2))
        {
            notfound = true;
            break;
        }
        if (Xor & power2)
        {
            ans += power2;
            for (int j = 0; j < n; j++)
                arr[j] += power2;
        }
        power2 *= 2;
    }
    if (notfound)
        return -1;
    else
        return ans;
}

int func2(int Max,long long arr[],int n)
{
    if(n==1)return -1;
    int i;
    for (i = 0; i <= Max; i++)
    {
        long long Xor = 0;
        for (int j = 0; j < n; j++)
        {
            Xor^= (arr[j] + i);
            
        }
        if (Xor == 0)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    while (true)
    {
        cout << endl;
        long long n, Max = 0;
        n = rand() % 10 + 1;
        n=(n&1)?n:n-1;
        cout << n << endl;
        long long arr[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = rand() % 10;
            cout << arr[i] << " ";
            Max = max(Max, arr[i]);
        }
        cout << endl;
        int ans1 = func1(arr, n);
        int ans2 = func2(Max, arr, n);
        if (ans1 != ans2)
        {
            cout << ans1 << " " << ans2 << "\n"
                 << "WrongAnswer\n";
            break;
        }
        else
        {
            cout << ans1 << " " << ans2 << "\n"
                 << "Correct\n";
        }
    }
    return 0;
}