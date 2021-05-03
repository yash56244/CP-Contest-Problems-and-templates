class DSU
{
private:
    vl parent;

public:
    DSU(ll n) { parent = vl(n + 1, -1); }

    ll get(ll x) { return (parent[x] < 0 ? x : parent[x] = get(parent[x])); } // Path Compression.

    bool sameSet(ll x, ll y) { return get(x) == get(y); }

    ll size(ll x) { return -parent[get(x)]; }

    bool unite(ll x, ll y)
    {
        x = get(x), y = get(y);

        if (x == y)
            return 0;

        if (parent[x] > parent[y]) // Union by size.
            swap(x, y);

        parent[x] += parent[y];

        parent[y] = x;

        return 1;
    }
};