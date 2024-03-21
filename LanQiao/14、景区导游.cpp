#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef long long i64;

vector<pair<int, int>> edge[N];
i64 fa[N], son[N], depth[N], siz[N], top[N], c[N], suf[N];
i64 sum[N];
void dfs1(int u, int f, i64 w)
{
    fa[u] = f;
    depth[u] = depth[f] + 1;
    siz[u] = 1;
    sum[u] = w;
    for (auto p : edge[u])
    {
        if (p.first == f)
            continue;
        dfs1(p.first, u, w + p.second);
        siz[u] += siz[p.first];
        if (siz[p.first] > siz[son[u]])
            son[u] = p.first;
    }
}

void dfs2(int u, int t)
{
    top[u] = t;
    if (!son[u])
        return;
    dfs2(son[u], t);
    for (auto p : edge[u])
    {
        if (p.first != son[u] && p.first != fa[u])
            dfs2(p.first, p.first);
    }
}

int lca(int x, int y)
{
    while (top[x] != top[y])
    {
        if (depth[top[x]] < depth[top[y]])
            swap(x, y);
        x = fa[top[x]];
    }
    return depth[x] > depth[y] ? y : x;
}

i64 _get(int x, int y)
{
    if (x == 0 || y == 0)
        return 0;
    return sum[x] + sum[y] - 2 * sum[lca(x, y)];
}

void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
        edge[v].push_back({u, w});
    }
    dfs1(1, 1, 0);
    dfs2(1, 1);
    for (int i = 1; i <= k; ++i)
        cin >> c[i];
    for (int i = k; i >= 1; --i)
        suf[i] = suf[i + 1] + _get(c[i], c[i + 1]);

    i64 pre = 0;
    for (int i = 1; i <= k; ++i)
    {
        cout << pre + _get(c[i - 1], c[i + 1]) + suf[i + 1] << " ";
        pre += _get(c[i - 1], c[i]);
    }
}

int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}