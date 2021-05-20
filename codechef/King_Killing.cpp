#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
// aacoder codes
#define pb push_back

using namespace std;
vector<ll> aacoder[200008], value, childs, ans;

void DFS(ll now, ll last)
{

    for (ll i = 0; i < aacoder[now].size(); i++)
    {
        ll child = aacoder[now][i];
        if (child != last)
            DFS(child, now);
    }
    childs.clear();

    for (ll i = 0; i < aacoder[now].size(); i++)
    {
        ll child = aacoder[now][i];
        if (child != last)
            childs.push_back(value[child]);
    }
    if (childs.size() > 0)
    {
        sort(childs.begin(), childs.end());

        ll x = childs[0];

        ll checker = 0;
        // aacoder
        for (ll i = 0; i < childs.size(); i++)
        {
            if (childs[i] != x)
                checker++;
        }
        if (checker == 0)
            value[now] += x + 1;
        if (checker != 0)
            value[now] += x + 2;
    }
    else
        value[now] = 0;
}

void DFS1(ll node, ll par, ll minh)
{
    for (ll i = 0; i < aacoder[node].size(); i++)
    {
        ll child = aacoder[node][i];
        minh = min(minh, value[node]);
        if (child != par)
        {
            if (value[child] >= minh - 1)
            {
                DFS1(child, node, minh);
            }
        }
    }
    if (value[node] == 0)
    {
        ans.push_back(node);
    }
}

void yash56244()
{
    ll N;
    cin >> N;
    value.assign(N + 1, 0);
    for (ll i = 0; i < N - 1; i++)
    {
        int l, r;
        cin >> l >> r;
        aacoder[l].pb(r), aacoder[r].pb(l);
    }
    DFS(1, 0);
    int minx = INT_MAX;
    for (ll i = 0; i < aacoder[1].size(); i++)
    {
        ll child = aacoder[1][i];
        if (value[child] < minx)
        {
            minx = value[child];
        }
    }

    for (ll i = 0; i < aacoder[1].size(); i++)
    {
        
        ll child = aacoder[1][i];
        if (value[child] == minx)
            
            DFS1(child, 1, minx);
    }

    sort(ans.begin(), ans.end());
    
    cout << ans.size() << " " << minx + 1 << endl;
    
    for (ll i = 0; i < ans.size(); ++i)
        cout << ans[i] << " ";
    cout << endl;

    for (ll i = 1; i <= N; ++i)
    {
        aacoder[i].clear();
    }
    value.clear();
    ans.clear();
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;
    cin >> t;
    while (t--)
    {
        yash56244();
    }
    return 0;
}