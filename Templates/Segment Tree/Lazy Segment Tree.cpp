// https://www.codechef.com/problems/RGCD
#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define FOR(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define FORL(i, a, n) for (int(i) = (a); (i) <= (n); (i)++)
#define FORR(i, a, n) for (int(i) = (a); (i) >= (n); (i)--)
#define FORSQ(i, a, n) for (int(i) = (a); (i) * (i) <= (n); ++(i))
#define FOREACH(a, b) for (auto &(a) : (b))
#define all(v) v.begin(), v.end()
#define SORT(v) sort(ALL(v))
#define log(args...)                             \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
    }
#define logcontainer(container)   \
    for (auto &(e) : (container)) \
        cout << (e) << " ";       \
    cout << endl;
void err(istream_iterator<string> it)
{
}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << *it << " = " << a << endl;
    err(++it, args...);
}

typedef long long int ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> pll;
typedef vector<pll> vll;
typedef vector<bool> vb;
typedef priority_queue<ll> maxheap;
typedef priority_queue<ll, vl, greater<ll>> minheap;
typedef map<ll, ll> mapll;

const ll inf = 1e18;
const ll mod = 1e9 + 7;
const ll maxn = 1e6 + 5;

ll Mod(ll a, ll b)
{
    return (b + a % b) % b;
}
template <typename Node, typename Update>
struct lazySegmentTree
{
    vector<Node> sg;
    vector<Update> lazy;
    vector<bool> mark;
    int n, i, j;
    Node zero = Node();
    Update clean = Update();
    template <typename T>
    void build(int v, int tl, int tr, T a[])
    {
        if (tl == tr)
        {
            sg[v] = a[tl];
        }
        else
        {
            int tm = (tl + tr) / 2;
            build(2 * v, tl, tm, a);
            build(2 * v + 1, tm + 1, tr, a);
            sg[v].combine(sg[2 * v], sg[2 * v + 1]);
        }
    }
    void push(int v, int tl, int tr)
    {
        if (mark[v])
        {
            int tm = (tl + tr) / 2;
            lazy[2 * v].combine(lazy[v]);
            lazy[2 * v + 1].combine(lazy[v]);
            lazy[v].apply(sg[2 * v], tl, tm);
            lazy[v].apply(sg[2 * v + 1], tm + 1, tr);
            mark[v] = 0;
            mark[2 * v] = mark[2 * v + 1] = 1;
            lazy[v] = clean;
        }
    }
    void update(int v, int tl, int tr, int l, int r, Update new_val)
    {
        if (l > r)
            return;
        if (l <= tl && r >= tr)
        {
            mark[v] = 1;
            lazy[v].combine(new_val);
            new_val.apply(sg[v], tl, tr);
        }
        else
        {
            push(v, tl, tr);
            int tm = (tl + tr) / 2;
            update(2 * v, tl, tm, l, min(r, tm), new_val);
            update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, new_val);
            sg[v].combine(sg[2 * v], sg[2 * v + 1]);
        }
    }
    Node query(int v, int tl, int tr, int l, int r)
    {
        if (l > r)
            return zero;
        if (l <= tl && r >= tr)
        {
            return sg[v];
        }
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        Node a, b, ans;
        a = query(2 * v, tl, tm, l, min(r, tm));
        b = query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
        ans.combine(a, b);
        return ans;
    }
    template <typename T>
    void build(T a[], int l)
    {
        n = l;
        sg.resize(4 * n + 4);
        lazy.resize(4 * n + 4);
        mark.resize(4 * n + 4);
        build(1, 0, n - 1, a);
    }
    void update(int l, int r, Update new_val)
    {
        update(1, 0, n - 1, l, r, new_val);
    }
    int query(int l, int r)
    {
        return query(1, 0, n - 1, l, r).v;
    }
};
struct update
{
    ll v = 1, i, j;
    update() {}
    update(ll val)
    {
        v = val;
    }
    void combine(update &other)
    {
        v *= other.v; // Change this for range update
    }
    template <typename Node>
    void apply(Node &x, int l, int r)
    {
        x.v *= v; // Change this also for range update
    }
};
struct node
{
    int i, j;
    ll v = 0;
    node() {}
    node(ll val)
    {
        v = val;
    }
    void combine(node &a, node &b)
    {
        v = __gcd(a.v, b.v); // Change this according to operation
    }
};

void yash56244()
{
    ll n, q;
    cin >> n >> q;
    ll arr[n];
    FOR(i, n)
    {
        cin >> arr[i];
    }
    lazySegmentTree<node, update> st;
    st.build(arr, n);
    while (q--)
    {
        ll t;
        cin >> t;
        if (t == 1)
        {
            ll l, r;
            cin >> l >> r;
            cout << st.query(l, r) << endl;
        }
        else
        {
            ll l, r, x;
            cin >> l >> r >> x;
            st.update(l, r, x);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
    {
        yash56244();
    }
    return 0;
}