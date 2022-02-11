#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

// string Decode(string str, int &it)
// {
//     string nstr,call1,call2;
//     int n = 0;
//     while (it < str.length())
//     {
//         if (str[it] >= 49 && str[it] <= 57)
//         {
//             n = str[it] - '1';
//             it++;
//         }
//         else if (str[it] == '[')
//         {
//             it++;
//             call1 += Decode(str, it);
//         }
//         else if (str[it] >= 97 && str[it] <= 122)
//         {
//             call2 += str[it];
//             it++;
//         }
//         else
//         {
//             for (int i = 1; i <= n; i++)
//             {
//                 nstr += nstr;
//             }
//             it++;
//         }
//     }
//     string rep=call1;
//     for (int i = 1; i <= n; i++)
//     {
//         call1 += rep;
//     }
//     return nstr+call;
// }

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string str;
    cin >> str;
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != ']')
        {
            st.push(str[i]);
        }
        else
        {
            string nstr, temp;
            while (st.size() && st.top() != '[')
            {
                nstr = st.top() + nstr;
                st.pop();
            }
            if (st.size())
                st.pop();
            int n = 0, ten = 1;
            while (st.size() && st.top() >= 48 && st.top() <= 57)
            {

                n += (st.top() - '0');
                n *= ten;
                ten *= 10;
                st.pop();
            }
            temp = nstr;
            for (int i = 1; i < n; i++)
                nstr += temp;

            for (int i = 0; i < nstr.length(); i++)
            {
                st.push(nstr[i]);
            }
        }
    }
    string ans;
    while (!st.empty())
    {
        ans = st.top() + ans;
        st.pop();
    }
    cout << ans << endl;
    return 0;
}
