class FloydWarshall
{
private:
    vvl dis;

public:
    FloydWarshall(vector<vll> &ad)
    {
        int n = ad.size();
        ll dist[n][n];
        FOR(i, n)
        {
            FOR(j, n)
            {
                if (i == j)
                {
                    dist[i][j] = 0;
                }
                else
                {
                    dist[i][j] = inf;
                }
            }
        }
        FOR(r, n)
        {
            FOREACH(c, ad[r])
            {
                dist[r][c.first] = c.second;
            }
        }
        FOR(k, n)
        {
            FOR(i, n)
            {
                FOR(j, n)
                {
                    if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != inf && dist[i][k] != inf))
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
        dis.resize(n);
        FOR(i, n)
        {
            dis[i].resize(n);
        }
        FOR(i, n)
        {
            FOR(j, n)
            {
                dis[i][j] = dist[i][j];
            }
        }
    }
    vvl getDist()
    {
        return dis;
    }
};
