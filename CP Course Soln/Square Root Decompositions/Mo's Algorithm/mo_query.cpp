#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

struct Query
{
    int indx, l, r, lb, rb;
};

bool cmp(Query a, Query b)
{
    // optimize sorting
    // odd sorted inc where as even as dec on r
    return (a.lb < b.lb) || (a.lb == b.lb && (a.lb & 1) ? a.r < b.r : a.r > b.r);

    // basic sorting
    // all sorted on inc r
    return (a.indx < b.indx) || (a.lb == b.lb && a.r < b.r);
}

class MOAlgorithm
{
    int n, q;
    vector<int> arr;

public:
    int curr_ans;
    // some extra data structres
    MOAlgorithm(int n, int q, vector<int> arr)
    {
        this->n = n;
        this->q = q;
        curr_ans = 0;
        this->arr = arr;
    }
    void add_element(int x)
    {
        // add the element to the ds
    }
    void remove_element(int x)
    {
        // remove the element from the ds
    }
};

int main()
{
    // input the query and other inputs
    int n, q;
    vector<int> arr, ans(q);
    // update the query
    vector<Query> queries;
    // sort() the inputed the query
    MOAlgorithm mo(n, q, arr);
    for (int i = 0, L = 0, R = 0; i <= q; i++)
    {
        while (R < queries[i].r)
            mo.add_element(++R);

        while (L > queries[i].l)
            mo.add_element(--R);

        while (R > queries[i].r)
            mo.add_element(R--);

        while (L < queries[i].l)
            mo.add_element(L++);
        ans[i] = mo.curr_ans;
    }
    // display the array content of ans;
    return 0;
}