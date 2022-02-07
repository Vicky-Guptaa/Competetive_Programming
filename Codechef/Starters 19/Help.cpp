#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int arr[] = {5, 6, 7, 8, 15};
    cout << lower_bound(arr, arr + 5, 15) - arr << "\n";
    return 0;
}