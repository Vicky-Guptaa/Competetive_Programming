#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

struct node
{
    int val;
    int ans;
    // can add more if required or remove
    node(ll v = 0, ll c = 0)
    {
        val = v;
        ans = c;
    }
};

class segTree
{
public:
    vector<node> segArr;
    vector<int> narr;
    int Xor;

    segTree(vector<int> arr)
    {
        narr = arr;
        int arrSize = arr.size();
        narr = arr;
        Xor = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            Xor = (Xor ^ arr[i]);
        }
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
        return node(left.val ^ right.val, max(left.ans, max(right.ans, left.val ^ right.val ^ Xor)));
    }

    void constructSegTree(int index, int startIndx, int endIndx)
    {
        if (startIndx == endIndx)
        {
            // Leaf Logic
            segArr[index] = node(narr[startIndx], narr[startIndx] ^ Xor);
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
            return node(0, 0);

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
            segArr[index] = node(val, 0);
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

int maxScore(int N, vector<int> A)
{
    segTree tree(A);
    return tree.getQuery(0, N - 1).ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (auto &x : arr)
    {
        cin >> x;
    }
    cout << maxScore(n, arr) << "\n";
    return 0;
}