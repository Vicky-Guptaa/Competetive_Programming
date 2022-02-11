#include <iostream>
using namespace std;

#define MAX 1000000000 

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, l, r;
        cin >> n >> l >> r;
        pair<int,int> minsum;
        minsum.first=MAX;
        for (int i = l; i <= r; i++)
        {
            int sum=0,num=i,nn=n;
            while (nn > 0)
            {
                int rem = nn % num;
                nn /= num;
                sum += rem;
            }
            if(minsum.first>=sum)
            {
                minsum.first=sum;
                minsum.second=i;

                cout<<minsum.second<<" "<<minsum.first<<endl;;
            }
        }
    }
    return 0;
}