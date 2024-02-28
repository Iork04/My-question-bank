// https://www.luogu.com.cn/problem/P1807
// 图论、拓扑排序
#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int>> t[1505];
vector<int> in(1505);
vector<int> ans(1505);
queue<int> q;
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        t[u].push_back({v, w});
        ++in[v];
    }
    for (int i = 2; i <= n; ++i)
    {
        ans[i] = -1e9; // 必须够小
        if (!in[i])
            q.push(i);
    }
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (auto &val : t[cur])
            if (!--in[val.first])
                q.push(val.first);
    }
    q.push(1);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (auto &val : t[cur])
        {
            if (ans[val.first] < ans[cur] + val.second)
                ans[val.first] = ans[cur] + val.second;
            if (!--in[val.first])
                q.push(val.first);
        }
    }
    cout << (ans[n] == -1e9 ? -1 : ans[n]);
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