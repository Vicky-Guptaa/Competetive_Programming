#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Hamming_Distance_Between_2_Integer(int m, int n)
{
    int Xor = n ^ m;
    int count = 0;
    while (Xor) // kerningham
    {
        count++;
        Xor = (Xor & (Xor - 1));
    }
    return count;
}

int Hamming_Distance_Array_Brute(int arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            res += Hamming_Distance_Between_2_Integer(arr[i], arr[j]);
        }
    }
    return res;
}

int Hamming_Distance_Array_Optimal(int arr[], int n)
{
    vector<int> bits(32, 0);
    for (int i = 0; i < n; i++)
    {
        int temp = arr[i], index = 0;
        while (temp)
        {
            if ((temp & 1))
                bits[index]++;
            index++;
            temp >>= 1;
        }
    }
    int res = 0;
    for (int i = 0; i < 32; i++)
    {
        res += bits[i] * (n - bits[i]);
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (auto &x : arr)
        cin >> x;
    cout << Hamming_Distance_Between_2_Integer(13, 65) << "\n";
    cout << Hamming_Distance_Array_Brute(arr, n) << "\n";
    cout << Hamming_Distance_Array_Optimal(arr, n) << "\n";
    return 0;
}