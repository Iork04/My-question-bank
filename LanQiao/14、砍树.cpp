#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
const int N = 1e5 + 10;

vector<vector<int>> edge(N);
i64 fa[N], son[N], siz[N], top[N], dep[N], diff[N];
map<pair<int, int>, int> id;

void dfs1(int u, int f)
{

    fa[u] = f;
    siz[u] = 1;
    dep[u] = dep[f] + 1;
    for (int v : edge[u])
    {

        if (v == f)
            continue;
        dfs1(v, u);
        siz[u] += siz[v];
        if (siz[v] > siz[son[u]])
            son[u] = v;
    }
}

void dfs2(int u, int t)
{
    top[u] = t;
    if (!son[u])
        return;
    dfs2(son[u], t);
    for (int v : edge[u])
    {
        if (son[u] != v && v != fa[u])
            dfs2(v, v);
    }
}

i64 lca(int x, int y)
{
    while (top[x] != top[y])
    {
        if (dep[top[x]] < dep[top[y]])
            swap(x, y);
        x = fa[top[x]];
    }
    return dep[x] > dep[y] ? y : x;
}

void dfs(int u, int fu)
{
    for (int v : edge[u])
    {
        if (v == fu)
            continue;
        dfs(v, u);
        diff[u] += diff[v];
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
        id[{u, v}] = i;
        id[{v, u}] = i;
    }
    dfs1(1, 1);
    dfs2(1, 1);

    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        diff[u]++, diff[v]++, diff[lca(u, v)] -= 2;
    }
    dfs(1, 1);
    int ans = -1;
    for (int i = 1; i <= n; i++)
    {
        if (diff[i] == m)
        {
            int ID = id[{i, fa[i]}];
            ans = max(ans, ID);
        }
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}