#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> e(n + 1);

    // 读取树的边
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    vector<int> fa(n + 1), dep(n + 1); // fa:父节点，dep:深度
    vector<bitset<300>> g;             // 存储路径的异或结果
    vector<int> u, v;

    // DFS，计算每个节点的父节点和深度
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

    // 枚举所有节点对，找出路径长度为 k 的路径
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            auto p = path(i, j);
            if (p.size() == k + 1)
            { // 路径长度为 k+1
                bitset<300> tp;
                for (auto x : p)
                {
                    if (x > 1)
                        tp.set(x - 2); // 设置异或路径
                }
                g.push_back(tp);
                u.push_back(i);
                v.push_back(j);
            }
        }
    }

    // 高斯消元过程
    for (int c = 0; c < n - 1; c++)
    {
        int p = -1;
        for (int r = c; r < g.size(); r++)
        {
            if (g[r][c])
            {
                p = r;
                break;
            }
        }
        if (p == -1)
        {
            cout << "No" << endl;
            return 0;
        }
        if (p > c)
            swap(g[p], g[c]), swap(u[p], u[c]), swap(v[c], v[p]);
        for (int r = c + 1; r < g.size(); r++)
        {
            if (g[r][c])
                g[r] = g[r] ^ g[c]; // 异或消去
        }
    }

    cout << "Yes" << endl;
    cout << "? " << n - 1;
    for (int i = 0; i < n - 1; i++)
        cout << " " << u[i] << " " << v[i];
    cout << endl;

    vector<int> b(n - 1);
    vector<vector<int>> gs(n - 1, vector<int>(n));
    for (int i = 0; i < n - 1; i++)
    {
        int x;
        cin >> x;
        b[i] = x;
        auto p = path(u[i], v[i]);
        g[i] = g[i] ^ g[i];
        for (auto x : p)
            if (x > 1)
                g[i].set(x - 2);
    }

    // 继续高斯消元
    for (int c = 0; c < n - 1; c++)
    {
        int p = -1;
        for (int r = c; r < n - 1; r++)
        {
            if (g[r][c])
            {
                p = r;
                break;
            }
        }

        if (p > c)
            swap(g[p], g[c]);
        for (int r = c + 1; r < n - 1; r++)
        {
            if (g[r][c])
                g[r] = g[r] ^ g[c], b[r] = b[r] ^ b[c];
        }
    }

    // 输出结果
    for (int r = n - 2; r >= 0; r--)
    {
        for (int j = r - 1; j >= 0; j--)
        {
            if (g[j][r])
                b[j] ^= b[r];
        }
    }

    cout << "!";
    for (int i = 0; i < n - 1; i++)
        cout << " " << b[i];
    cout << endl;
}
