#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

void Brute_Solve(unsigned long long arr[], int n)
{
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    if ((arr[i] ^ arr[j] ^ arr[k] ^ arr[l]) == 0)
                    {
                        cout << "Yes\n";
                        return;
                    }
                }
            }
        }
    }
    cout << "NO\n";
}

int main()
{
    int n;
    cin >> n;
    unsigned long long arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (n >= 130)
    {
        cout << "YES\n"; // Pigeon Hole Principle
    }
    else
    {
        Brute_Solve(arr, n);
    }
    return 0;
}

/*
#include<bits/stdc++.h>
typedef unsigned long long int ll;
using namespace std;

void isXor(ll arr[], int n) {

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                for (int l = k + 1; l < n; l++) {
                    if ((arr[i] ^ arr[j] ^ arr[k] ^ arr[l]) == 0) {
                        cout << "Yes";
                        return;
                    }
                }
            }
        }
    }
    cout << "No";
}

int main() {
    int n;
    cin >> n;
    ll arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (n >= 130) {
        cout << "Yes";
    } else {
        isXor(arr, n);
    }

    return 0;

}
*/
/*
5
9223372036854775808
9223372036854775809
9223372036854775810
9223372036854775812
9223372036854775816
*/