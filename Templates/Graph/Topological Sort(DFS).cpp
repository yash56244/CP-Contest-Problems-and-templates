void topoDFS(ll node)
{
    FOREACH(i, adj[node])
    {
        if (!vis[i])
        {
            vis[i] = true;
            topoDFS(i);
        }
    }
    toposort.pb(node);
}

void topoSort()
{
    FORL(i, 1, n - 1)
    {
        if (!vis[i])
        {
            vis[i] = true;
            topoDFS(i);
        }
    }
    reverse(begin(toposort), end(toposort));
    // The vector `toposort` is now topologically sorted
}