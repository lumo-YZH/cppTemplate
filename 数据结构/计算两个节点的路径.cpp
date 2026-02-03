auto dfs = [&](auto dfs, int u, int f) -> void
{
    fa[u] = f;
    dep[u] = dep[f] + 1;
    for (auto son : e[u])
    {
        if (son != f)
            dfs(dfs, son, u);
    }
};
// 计算两个节点的路径
auto path = [&](int x, int y) -> vector<int>
{
    vector<int> res;
    if (dep[x] < dep[y])
        swap(x, y);
    while (dep[x] != dep[y])
    {
        res.push_back(x);
        x = fa[x];
    }
    while (x != y)
    {
        res.push_back(x);
        res.push_back(y);
        x = fa[x];
        y = fa[y];
    }
    res.push_back(x);
    return res;
};
dfs(dfs, 1, 0);