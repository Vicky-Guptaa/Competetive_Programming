#include <iostream>
using namespace std;

int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        long long int n, k;
        cin >> n >> k;
        long long int arr[n];
        long long int Max = 0;
        for (long long int i = 0; i < n; i++)
        {
            cin >> arr[i];
            Max = max(Max, arr[i]);
        }
        
        long long int lsize =0;
        while(Max)
        {
            Max/=2;
            lsize++;
        }
        long long int bitarry [lsize]={0};

        for (long long int i = 0; i < n; i++)
        {
            long long int j = 0;
            long long int temp = arr[i];
            while (temp)
            {
                bitarry[j] += temp % 2;
                temp /= 2;
                j++;
            }
        }
        long long int count = 0;
        for (long long int i = 0; i < lsize; i++)
        {
            if(bitarry[i]%k==0)
            {
                count+=bitarry[i]/k;
            }
            else
            {
                count+=(bitarry[i]/k)+1;
            }
        }
        cout << count << endl;
    }
    return 0;
}