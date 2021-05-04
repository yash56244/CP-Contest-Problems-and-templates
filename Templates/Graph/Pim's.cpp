class Prim
{
private:
    ll cost = 0;
    bool mstPossible;
    vb selected, vis;
    vl minimumdist;
    set<pll> s;

public:
    Prim(vector<vll> &adj, ll n) // pairs in adj list are of the form {weight, second vertex};
    {
        selected.assign(n, false);
        vis.assign(n, false);
        minimumdist.assign(n, inf);
        minimumdist[1] = 0;
        s.insert({0, 1});
        FORL(i, 1, n - 1)
        {
            if (s.empty())
            {
                cost = -1;
                break;
            }
            int v = s.begin()->second;
            vis[v] = true;
            cost += s.begin()->first;
            s.erase(s.begin());
            FOREACH(pr, adj[v])
            {
                if (!vis[pr.second] && pr.first < minimumdist[pr.second])
                {
                    s.erase({minimumdist[pr.second], pr.second});
                    minimumdist[pr.second] = pr.first;
                    s.insert({pr.first, pr.second});
                }
            }
        }
        mstPossible = (cost != -1);
    }
    ll getCost()
    {
        return (mstPossible ? cost : -1);
    }
};
