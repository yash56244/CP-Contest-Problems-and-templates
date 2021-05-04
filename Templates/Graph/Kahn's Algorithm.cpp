void kahns(vl in_degree)
{
    queue<ll> q;
    ll cnt = 0;
    vl topoSort;
    FORL(i, 1, n - 1)
    {
        if (in_degree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        ll node = q.front();
        q.pop();
        topoSort.push_back(node);
        FOREACH(next, adj[node])
        {
            in_degree[next]--;
            if (in_degree[next] == 0)
                q.push(next);
        }
        cnt++;
        // Put problem-specific processing here
    }
}