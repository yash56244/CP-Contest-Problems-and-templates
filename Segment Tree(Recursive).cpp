#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define FOR(i, n) for (int(i) = 0; (i) < (n); (i)++)

// T is the type of input array element
// V is the type of the required aggregate statistic
template <class T, class V>
class SegmentTreeNode
{
    // variables
public:
    void assignLeaf(T value)
    {
    }

    void merge(SegmentTreeNode &left, SegmentTreeNode &right)
    { // merge the aggregate statistics of left and right
    }

    V getValue()
    { // return the value of required aggregate statistic
    }
};

template <class T, class V>
class SegmentTree
{
    int n;
    vector<SegmentTreeNode<T, V>> nodes;

public:
    SegmentTree(T arr[], int n)
    {
        this->n = n;
        nodes.resize(getSegmentTreeSize(n));
        buildTree(arr, 1, 0, n - 1);
    }

    V query(int lo, int hi)
    {
        SegmentTreeNode<T, V> result = query(1, 0, n - 1, lo, hi);
        return result.getValue();
    }

    void update(int index, T value)
    {
        update(1, 0, n - 1, index, value);
    }

private:
    void buildTree(int arr[], int stIndex, int lo, int hi)
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

    SegmentTreeNode<T, V> query(int stIndex, int left, int right, int lo, int hi)
    {
        if (left == lo && right == hi)
            return nodes[stIndex];

        int mid = (left + right) / 2;
        if (lo > mid)
            return query(2 * stIndex + 1, mid + 1, right, lo, hi);
        if (hi <= mid)
            return query(2 * stIndex, left, mid, lo, hi);

        SegmentTreeNode<T, V> leftResult = query(2 * stIndex, left, mid, lo, mid);
        SegmentTreeNode<T, V> rightResult = query(2 * stIndex + 1, mid + 1, right, mid + 1, hi);
        SegmentTreeNode<T, V> result;
        result.merge(leftResult, rightResult);
        return result;
    }

    int getSegmentTreeSize(int n)
    {
        int size = 1;
        for (; size < n; size <<= 1)
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

int main()
{
    ios_base::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int arr[n];
    FOR(i, n)
    {
        cin >> arr[i];
    }
    SegmentTree<int, int> st(arr, n);
    return 0;
}