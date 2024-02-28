// https://www.luogu.com.cn/problem/P1983
// 图论、拓扑
#include <bits/stdc++.h>
using namespace std;
int n, m, k, v, st[1005];
int in[1005], out[1005];
bool is[1005];
bool vis[1005][1005];

int bfs()
{
    int res = 0;
    while (1)
    {
        queue<int> q;

        for (int i = 1; i <= n; ++i)
            if (!in[i])
            {
                in[i] = -1;
                q.push(i);
            }
        if (q.empty())
            break;
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (int i = 1; i <= n; ++i)
                if (vis[cur][i])
                {
                    vis[cur][i] = 0;
                    --in[i];
                }
        }
        res++;
    }
    return res;
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >> k;
        memset(is, 0, sizeof(is));
        for (int j = 1; j <= k; ++j)
        {
            cin >> st[j];
            is[st[j]] = 1;
        }
        for (int j = st[1]; j <= st[k]; ++j)
            if (!is[j])
                for (int l = 1; l <= k; ++l)
                    if (!vis[j][st[l]])
                    {
                        vis[j][st[l]] = 1;
                        ++in[st[l]];
                    }
    }
    cout << bfs();
}

int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    // freopen("./in.in", "r", stdin);
    int _ = 1;
    // cin >> _;
    while (_--)
        solve();
    return 0;
}