#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

struct node
{
    ll val;
    ll cnt;
    // can add more if required or remove
    node(ll v = 0, ll c = 0)
    {
        val = v;
        cnt = c;
    }
};

class segTree
{
public:
    vector<node> segArr, lazy;
    vector<ll> narr;

    segTree(vector<ll> arr)
    {
        int arrSize = arr.size();
        narr = arr;
        /*
 we are constructing tree in form of array linearly therefore
we have to make 4*n size array for n size given array
*/
        segArr.resize(4 * arrSize);
        lazy.resize(4 * arrSize);
        constructSegTree(0, 0, arrSize - 1);
    }

    // here you can change the combine logic according to questions
    node Combine(node &left, node &right)
    {
        return node(left.val + right.val);
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
            return node(0);

        // lazy propagation / clear the lazy updates
        if (lazy[index].val != 0)
        {
            // pending updates
            // update the segmenet tree node
            node newNode = node(lazy[index].val * (endIndx - startIndx + 1));
            segArr[index] = Combine(segArr[index], newNode);
            if (startIndx != endIndx)
            {
                // propagaetd the updated value
                lazy[2 * index + 1] = Combine(lazy[2 * index + 1], lazy[index]);
                lazy[2 * index + 2] = Combine(lazy[2 * index + 2], lazy[index]);
            }
            lazy[index] = node(0);
        }

        // complete overlap
        if (startIndx >= lquery && endIndx <= rquery)
            return segArr[index];

        // partial overlap
        int midIndx = startIndx + (endIndx - startIndx) / 2;
        node left = getQuery(index * 2 + 1, startIndx, midIndx, lquery, rquery);
        node right = getQuery(index * 2 + 2, midIndx + 1, endIndx, lquery, rquery);

        return Combine(left, right);
    }

    void updateQuery(int index, int startIndx, int endIndx, int lquery, int rquery, int val)
    {
        // no overlap
        if (startIndx > rquery || lquery > endIndx)
            return;

        // lazy propagation / clear the lazy updates
        if (lazy[index].val != 0)
        {
            // pending updates
            // update the segmenet tree node
            node newNode = node(lazy[index].val * (endIndx - startIndx + 1));
            segArr[index] = Combine(segArr[index], newNode);
            if (startIndx != endIndx)
            {
                // propagaetd the updated value
                lazy[2 * index + 1] = Combine(lazy[2 * index + 1], lazy[index]);
                lazy[2 * index + 2] = Combine(lazy[2 * index + 2], lazy[index]);
            }
            lazy[index] = node(0);
        }

        // complete overlap
        if (startIndx >= lquery && endIndx <= rquery)
        {
            node newNode = node(val * (endIndx - startIndx + 1));
            segArr[index] = Combine(segArr[index], newNode);
            if (startIndx != endIndx)
            {
                // propagaetd the updated value
                node valNode = node(val);
                lazy[2 * index + 1] = Combine(lazy[2 * index + 1], valNode);
                lazy[2 * index + 2] = Combine(lazy[2 * index + 2], valNode);
            }
            return;
        }

        // partial overlap
        int midIndx = startIndx + (endIndx - startIndx) / 2;
        updateQuery(2 * index + 1, startIndx, midIndx, lquery, rquery, val);
        updateQuery(2 * index + 2, midIndx + 1, endIndx, lquery, rquery, val);
        segArr[index] = Combine(segArr[2 * index + 1], segArr[2 * index + 2]);
    }

    // Use To Get The result of the queries
    void updateQuery(int l, int r, int value)
    {
        updateQuery(0, 0, (int)narr.size() - 1, l, r, value);
    }

    node getQuery(int lquery, int rquery)
    {
        return getQuery(0, 0, (int)narr.size() - 1, lquery, rquery);
    }
};

int main()
{
    int n = 4;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    segTree tree(arr);
    cout << tree.getQuery(0, n - 1).val << "\n";
    tree.updateQuery(3, n - 1, 10);
    cout << tree.getQuery(3, n - 1).val << "\n";
    return 0;
}