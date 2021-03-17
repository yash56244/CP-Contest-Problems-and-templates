#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define FOR(i, n) for (ll(i) = 0; (i) < (n); (i)++)
#define FORL(i, a, n) for (ll(i) = (a); (i) <= (n); (i)++)
#define FORR(i, a, n) for (ll(i) = (a); (i) >= (n); (i)--)
#define FORSQ(i, a, n) for (ll(i) = (a); (i) * (i) <= (n); ++(i))
#define FOREACH(a, b) for (auto &(a) : (b))
#define ALL(v) v.begin(), v.end()

typedef long long int ll;
typedef pair<ll, ll> pll;
typedef pair<char, char> pcc;
typedef vector<pll> vll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef map<ll, ll> mapll;

using T = int; // T is the type of input array element
using V = int; // V is the type of the required aggregate statistic

struct SegmentTreeNode
{
    // variables to store aggregate statistics and
    // any other information required to merge these
    // aggregate statistics to form parent nodes

    void assignLeaf(T value)
    {
        // Given the value of an input array element,
        // build aggregate statistics for this leaf node
    }

    void merge(SegmentTreeNode &left, SegmentTreeNode &right)
    {
        // merge the aggregate statistics of left and right
        // children to form the aggregate statistics of
        // their parent node
    }

    V getValue()
    {
        // return the value of required aggregate statistic
        // associated with this node
    }
};

// T is the type of input array elements
// V is the type of required aggregate statistic
template <class T, class V>
class SegmentTree
{
    SegmentTreeNode *nodes;
    int N;

public:
    SegmentTree(T arr[], int N)
    {
        this->N = N;
        nodes = new SegmentTreeNode[getSegmentTreeSize(N)];
        buildTree(arr, 1, 0, N - 1);
    }

    ~SegmentTree()
    {
        delete[] nodes;
    }

    V getValue(int lo, int hi)
    {
        SegmentTreeNode result = getValue(1, 0, N - 1, lo, hi);
        return result.getValue();
    }

    void update(int index, T value)
    {
        update(1, 0, N - 1, index, value);
    }

private:
    void buildTree(T arr[], int stIndex, int lo, int hi)
    {
        if (lo == hi)
        {
            nodes[stIndex].assignLeaf(arr[lo]);
            return;
        }

        int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
        buildTree(arr, left, lo, mid);
        buildTree(arr, right, mid + 1, hi);
        nodes[stIndex].merge(nodes[left], nodes[right]);
    }

    SegmentTreeNode getValue(int stIndex, int left, int right, int lo, int hi)
    {
        if (left == lo && right == hi)
            return nodes[stIndex];

        int mid = (left + right) / 2;
        if (lo > mid)
            return getValue(2 * stIndex + 1, mid + 1, right, lo, hi);
        if (hi <= mid)
            return getValue(2 * stIndex, left, mid, lo, hi);

        SegmentTreeNode leftResult = getValue(2 * stIndex, left, mid, lo, mid);
        SegmentTreeNode rightResult = getValue(2 * stIndex + 1, mid + 1, right, mid + 1, hi);
        SegmentTreeNode result;
        result.merge(leftResult, rightResult);
        return result;
    }

    int getSegmentTreeSize(int N)
    {
        int size = 1;
        for (; size < N; size <<= 1)
            ;
        return size << 1;
    }

    void update(int stIndex, int lo, int hi, int index, T value)
    {
        if (lo == hi)
        {
            nodes[stIndex].assignLeaf(value);
            return;
        }

        int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
        if (index <= mid)
            update(left, lo, mid, index, value);
        else
            update(right, mid + 1, hi, index, value);

        nodes[stIndex].merge(nodes[left], nodes[right]);
    }
};

void yash56244()
{
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    cin >> t;
    while (t--)
    {
        yash56244();
    }
    return 0;
}