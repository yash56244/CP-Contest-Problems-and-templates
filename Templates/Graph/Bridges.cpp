class Bridge
{
private:
    vb vis;
    vl disc, low, parent;
    vvl adj;
    vll bridges;
    void dfs(ll s)
    {
        static int time = 0;
        vis[s] = true;
        disc[s] = low[s] = ++time;
        FOREACH(v, adj[s])
        {
            if (!vis[v])
            {
                parent[v] = s;
                dfs(v);
                low[s] = min(low[s], low[v]);
                if (low[v] > disc[s])
                    bridges.push_back({s, v});
            }
            else if (v != parent[s])
                low[s] = min(low[s], disc[v]);
        }
    }

public:
    /* adj is 1-based indexed graph and n is no of vertices */
    Bridge(vvl &ad)
    {
        int n = ad.size();
        vis.resize(n);
        disc.resize(n);
        low.resize(n);
        parent.resize(n);
        ap.resize(n);
        adj.resize(n);
        adj = ad;
        FORL(i, 1, n - 1)
        {
            if (!vis[i])
            {
                dfs(i);
            }
        }
    }
    vll getBridges()
    {
        return bridges;
    }
};