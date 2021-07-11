class DSU
{
private:
    vector<int> parent, size;

public:
    DSU(int n)
    {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        size.resize(n, 1);
    }
    int find(int a)
    {
        while (parent[a] != a)
        {
            parent[a] = parent[parent[a]]; // Path Compression.
            a = parent[a];
        }
        return a;
    }
    bool same(int a, int b)
    {
        return find(a) == find(b);
    }
    void unite(int a, int b) // Union by size.
    {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA == rootB)
        {
            return; // If A and B have same root, means they are connected.
        }
        if (size[rootA] < size[rootB])
        {
            parent[rootA] = rootB;
            size[rootB] += size[rootA];
        }
        else
        {
            parent[rootB] = rootA;
            size[rootA] += size[rootB];
        }
    }
    int _size(int a) // Size of subset in which a is present.
    {
        int rootA = find(a);
        return size[rootA];
    }
};