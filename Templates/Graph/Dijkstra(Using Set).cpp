class Dijkstra
{
private:
    vector<vll> adj;
    set<pll> s;
    vl dist;

    void dijkstra(ll src)
    {
        s.insert({0, src});
        dist[src] = 0;
        while (!s.empty())
        {
            pll top = *(s.begin());
            s.erase(s.begin());
            int u = top.second;
            FOREACH(pr, adj[u])
            {
                int v = pr.first;
                ll wt = pr.second;
                if (dist[v] > dist[u] + wt)
                {
                    if (dist[v] != inf)
                        s.erase(s.find({dist[v], v}));
                    dist[v] = dist[u] + wt;
                    s.insert({dist[v], v});
                }
            }
        }
    }

public:
    Dijkstra(vector<vll> &ad, ll src)
    {
        int n = ad.size();
        dist.assign(n, inf);
        adj = ad;
        dijkstra(src);
    }
    vl getDist()
    {
        return dist;
    }
};