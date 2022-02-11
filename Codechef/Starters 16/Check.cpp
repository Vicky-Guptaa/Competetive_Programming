#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    int arr[100001] = {0};
    arr[0] = 1;
    arr[1] = 1;
    for (long long i = 2; i <= 100000; i++)
    {
        if (arr[i] == 0)
        {
            for (long long j = i * i; j <= 100000; j += i)
            {
                arr[j] = 1;
            }
        }
    }
    int presum[100001] = {0};
    int sum = 0;
    for (int i = 0; i <= 100000; i++)
    {
        sum += arr[i];
        presum[i] = sum;
    }
    while (true)
    {
        int x=1, y=0;
        while (y < x)
        {
            x = (rand() % 10000) + 10000;
            y = (rand() % 10000) + 10000;
        }
        cout << x << " " << y << endl;
        int count = 0;
        int total = y - x;
        int nonprime = presum[y] - presum[x];
        int prime = total - nonprime;

        if (arr[x + 1] == 0)
        {
            prime--;
        }
        while (x < y)
        {
            if (arr[x + 2] == 0)
            {
                x += 2;
            }
            else
            {
                x += 1;
            }
            count++;
        }
        if (count != total - prime)
        {
            cout << "Wrong" << endl;
        }
        else
            cout <<count<<endl<< "Ok" << endl;
    }

    return 0;
}
