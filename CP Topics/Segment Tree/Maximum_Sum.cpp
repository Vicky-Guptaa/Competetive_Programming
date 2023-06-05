#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

struct node
{
    ll val;
    ll firstMax;
    ll secondMax;
    // can add more if required or remove
    node(ll v = 0)
    {
        val = v;
        firstMax = v;
        secondMax = 0;
    }
};

class segTree
{
public:
    vector<node> segArr;
    vector<ll> narr;

    segTree(vector<ll> arr)
    {
        narr = arr;
        int arrSize = arr.size();
        narr = arr;
        /*
 we are constructing tree in form of array linearly therefore
we have to make 4*n size array for n size given array
*/
        segArr.resize(4 * arrSize);
        constructSegTree(0, 0, arrSize - 1);
    }

    // here you can change the combine logic according to questions
    node Combine(node &left, node &right)
    {
        node res = node(0);
        if (left.firstMax > right.firstMax)
        {
            res.firstMax = left.firstMax;
            if (left.secondMax > right.firstMax)
            {
                res.secondMax = left.secondMax;
            }
            else
            {
                res.secondMax = right.firstMax;
            }
        }
        else
        {
            res.firstMax = right.firstMax;
            if (right.secondMax > left.firstMax)
            {
                res.secondMax = right.secondMax;
            }
            else
            {
                res.secondMax = left.firstMax;
            }
        }
        return res;
    }

    void constructSegTree(int index, int startIndx, int endIndx)
    {
        if (startIndx == endIndx)
        {
            // Leaf Logic
            segArr[index] = node(narr[startIndx]);
            return;
        }
        int midIndx = startIndx + (endIndx - startIndx) / 2;

        constructSegTree(2 * index + 1, startIndx, midIndx);
        constructSegTree(2 * index + 2, midIndx + 1, endIndx);
        segArr[index] = Combine(segArr[2 * index + 1], segArr[2 * index + 2]);
    }
    node getQuery(int index, int startIndx, int endIndx, int lquery, int rquery)
    {
        // no overlap
        if (startIndx > rquery || lquery > endIndx)
            return node(-1e9);

        // complete overlap
        if (startIndx >= lquery && endIndx <= rquery)
            return segArr[index];

        // partial overlap
        int midIndx = startIndx + (endIndx - startIndx) / 2;
        node left = getQuery(index * 2 + 1, startIndx, midIndx, lquery, rquery);
        node right = getQuery(index * 2 + 2, midIndx + 1, endIndx, lquery, rquery);

        return Combine(left, right);
    }

    void updateQuery(int index, int startIndx, int endIndx, int position, int val)
    {
        if (position < startIndx || position > endIndx)
            return;

        if (startIndx == endIndx)
        {
            // Leaf Condition
            segArr[index] = node(val);
            narr[startIndx] = val;
            return;
        }

        int midIndx = startIndx + (endIndx - startIndx) / 2;
        updateQuery(2 * index + 1, startIndx, midIndx, position, val);
        updateQuery(2 * index + 2, midIndx + 1, endIndx, position, val);
        segArr[index] = Combine(segArr[2 * index + 1], segArr[2 * index + 2]);
    }

    // Use To Get The result of the queries
    void updateQuery(int postion, int value)
    {
        updateQuery(0, 0, (int)narr.size() - 1, postion, value);
    }

    node getQuery(int lquery, int rquery)
    {
        return getQuery(0, 0, (int)narr.size() - 1, lquery, rquery);
    }
};
// use 0 based indexing while calling the update and query func

int main()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (auto &x : arr)
        cin >> x;

    segTree tree(arr);

    int q;
    cin >> q;
    while (q--)
    {
        char ch;
        cin >> ch;
        int b, c;
        cin >> b >> c;
        if (ch == 'Q')
        {
            node ans = tree.getQuery(b - 1, c - 1);
            cout << ans.firstMax + ans.secondMax << "\n";
        }
        else
        {
            tree.updateQuery(b - 1, c);
        }
    }

    return 0;
}