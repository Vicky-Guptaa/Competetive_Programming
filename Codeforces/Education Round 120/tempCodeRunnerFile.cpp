#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int arr[5][5][5];
    for (int i = 0; i < 15; i++)
    {
        ***(arr + i) = 0;
        cout << ***(arr + i) << " ";
    }

    return 0;
}