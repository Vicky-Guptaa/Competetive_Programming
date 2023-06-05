#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

struct node
{
    ll mini;
    ll cnt;
    // can add more if required or remove
    node(ll m = 1e9, ll c = 0)
    {
        // similarly for max we make m=-1e9 and change the combine logic we change m=-1e9 bcoz when we create null we get the min val so we dont consider the value
        mini = m;
        cnt = c;
    }
};

class segTree
{
    node getNode(int index, int startIndx, int endIndx, int lquery, int rquery)
    {
        if (startIndx > rquery || lquery > endIndx)
            return node();

        if (startIndx >= lquery && endIndx <= rquery)
            return segArr[index];

        int midIndx = startIndx + (endIndx - startIndx) / 2;
        node left = getNode(index * 2 + 1, startIndx, midIndx, lquery, rquery);
        node right = getNode(index * 2 + 2, midIndx + 1, endIndx, lquery, rquery);

        return Combine(left, right);
    }

    void updateNode(int index, int startIndx, int endIndx, int position, int val)
    {
        if (position < startIndx || position > endIndx)
            return;

        if (startIndx == endIndx)
        {
            // Leaf Condition
            segArr[index] = node(val, 1);
            narr[startIndx] = val;
            return;
        }

        int midIndx = startIndx + (endIndx - startIndx) / 2;
        updateNode(2 * index + 1, startIndx, midIndx, position, val);
        updateNode(2 * index + 2, midIndx + 1, endIndx, position, val);
        segArr[index] = Combine(segArr[2 * index + 1], segArr[2 * index + 2]);
    }

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
        if (left.mini > right.mini)
        {
            return right;
        }

        if (left.mini < right.mini)
        {
            return left;
        }

        return node(left.mini, left.cnt + right.cnt);
    }

    void constructSegTree(int index, int startIndx, int endIndx)
    {
        if (startIndx == endIndx)
        {
            // Leaf Logic
            segArr[index] = node(narr[startIndx], 1);
            return;
        }
        int midIndx = startIndx + (endIndx - startIndx) / 2;

        constructSegTree(2 * index + 1, startIndx, midIndx);
        constructSegTree(2 * index + 2, midIndx + 1, endIndx);
        segArr[index] = Combine(segArr[2 * index + 1], segArr[2 * index + 2]);
    }

    // Use To Get The result of the queries
    void updateQuery(int postion, int value)
    {
        updateNode(0, 0, (int)narr.size() - 1, postion, value);
    }

    node getQuery(int lquery, int rquery)
    {
        return getNode(0, 0, (int)narr.size() - 1, lquery, rquery);
    }
};

int main()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    segTree tree(arr);
    node ans = tree.getQuery(0, n - 1);
    cout << ans.mini << " " << ans.cnt << "\n";
    tree.updateQuery(2, 1);
    ans = tree.getQuery(0, n - 1);
    cout << ans.mini << " " << ans.cnt << "\n";

    return 0;
}