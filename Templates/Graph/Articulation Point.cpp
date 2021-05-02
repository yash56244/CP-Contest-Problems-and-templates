class ArticulationPoint
{
private:
    vb vis, ap;
    vl disc, low, parent, aps;
    vvl adj;
    void dfs(ll s)
    {
        static int time = 0;
        int children = 0;
        vis[s] = true;
        disc[s] = low[s] = ++time;
        FOREACH(v, adj[s])
        {
            if (!vis[v])
            {
                children++;
                parent[v] = s;
                dfs(v);
                low[s] = min(low[s], low[v]);
                if (parent[v] == 0 && children > 1)
                    ap[s] = true;
                if (parent[v] && low[v] >= disc[s])
                    ap[s] = true;
            }
            else if (v != parent[s])
                low[s] = min(low[s], disc[v]);
        }
    }

public:
    /* adj is 1-based indexed graph and n is no of vertices */
    ArticulationPoint(vvl &ad)
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
    vl getAP()
    {
        FORL(i, 1, ap.size() - 1)
        {
            if (ap[i])
            {
                aps.push_back(i);
            }
        }
        return aps;
    }
};