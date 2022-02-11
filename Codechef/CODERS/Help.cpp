#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

long long Func1(int arr[], int n)
{
    long long answer = 0, Max = 0, i = 0;
    int temp[n];
    while (i < n)
    {
        for (int k = 0; k < n; k++)
            temp[k] = arr[k];
        answer = 0;
        int j = i;
        for (; temp[j] != 0; j = (j + 1) % n)
        {
            answer++;
            temp[j]--;
        }
        Max = max(Max, answer);
        i++;
    }
    return Max;
}

long long Func2(int arr[], int n, vector<int> zero, int Min)
{
    int answer = 0;
    if (!zero.empty())
    {
        if (zero.size() == 1)
            return n - 1;
        else
        {
            int Max = 0;
            for (int i = 1; i < zero.size(); i++)
            {
                Max = max(Max, zero[i] - zero[i - 1] - 1);
            }
            Max = max(Max, zero[0] + n - zero[zero.size() - 1] - 1);
            return Max;
        }
    }
    answer = (long long)n * Min;
    for (int i = 0; i < n; i++)
    {
        arr[i] -= Min;
        if (arr[i] == 0)
            zero.push_back(i);
    }

    if (!zero.empty())
    {
        if (zero.size() == 1)
            answer += n - 1;
        else
        {
            int Max = 0;
            for (int i = 1; i < zero.size(); i++)
            {
                Max = max(Max, zero[i] - zero[i - 1] - 1);
            }
            Max = max(Max, zero[0] + n - zero[zero.size() - 1] - 1);
            answer += Max;
        }
    }
    return answer;
}

int main()
{
    while (1)
    {
        int n = rand() % 10 + 1;
        cout << n << "\n";
        int arr[n], Min = 1e8;
        long long answer;
        vector<int> zero;
        for (int i = 0; i < n; i++)
        {
            arr[i] = rand() % 1000;
            cout << arr[i] << " ";
            if (Min > arr[i])
            {
                Min = arr[i];
            }
            if (arr[i] == 0)
                zero.push_back(i);
        }
        cout << "\n";
        long long ans1 = Func1(arr, n);
        long long ans2 = Func2(arr, n, zero, Min);
        if (ans1 != ans2)
        {
            cout << ans1 << " " << ans2 << "\n";
            cout << "Wrong Answer\n\n";
            break;
        }
        else
        {
            cout << ans1 << " " << ans2 << "\n";
            cout << "Ok\n\n";
        }
    }
    return 0;
}