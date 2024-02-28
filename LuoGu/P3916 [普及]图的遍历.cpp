// https://www.luogu.com.cn/problem/P3916
// 图论、反向建图dfs
#include <bits/stdc++.h>
using namespace std;

int m, n, u, v;
vector<int> a[100010];
vector<int> ans(100010, 0);
bool b[100010];

int dfs(int x, int d)
{
    if (ans[x])
        return ans[x];
    ans[x] = d;
    for (int &val : a[x])
        dfs(val, d);
    return ans[x];
}

void solve()
{
    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        cin >> v >> u;
        a[u].push_back(v);
    }
    for (int i = n; i > 0; --i)
        dfs(i, i);
    for (int i = 1; i <= n; ++i)
        cout << dfs(i, i) << " ";

    // dfs(1);
}

int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    freopen("./in.in", "r", stdin);
    int _ = 1;
    // cin >> _;
    while (_--)
        solve();
    return 0;
}