class DSU
{
private:
    vl parent;

public:
    DSU(ll n) { parent = vl(n + 1, -1); }
    ll get(ll x) { return (parent[x] < 0 ? x : parent[x] = get(parent[x])); }
    bool sameSet(ll x, ll y) { return get(x) == get(y); }
    ll size(ll x) { return -parent[get(x)]; }
    bool unite(ll x, ll y)
    {
        x = get(x), y = get(y);
        if (x == y)
            return 0;
        if (parent[x] > parent[y])
            swap(x, y);
        parent[x] += parent[y];
        parent[y] = x;
        return 1;
    }
};

class Kruskal
{
private:
    ll cost = 0, cnt = 0;
    vll mst;
    bool mstPossible;

public:
    Kruskal(vector<pair<ll, pll>> &edgs, ll n)
    {
        DSU dsu(n);
        sort(edgs.begin(), edgs.end());
        FOREACH(e, edgs)
        {
            if (dsu.unite(e.second.first, e.second.second))
            {
                cost += e.first;
                cnt++;
                mst.push_back({e.second.first, e.second.second});
            }
        }
        mstPossible = (cnt == n - 1);
    }
    vll getMST()
    {
        return mst;
    }
    ll getCost() // Returns -1 if mst not possible.
    {
        return (mstPossible ? cost : -1);
    }
};