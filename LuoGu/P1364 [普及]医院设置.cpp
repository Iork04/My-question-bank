// https://www.luogu.com.cn/problem/P1364
// dp、bfs
#include <bits/stdc++.h>
using namespace std;
bool v[105];
bool g[105][105];
int num[105];
int n, ans = 0xfffffff;

struct node
{
    int u, step;
};

int bfs(int x)
{
    memset(v, 0, sizeof(v));
    v[x] = 1;
    queue<node> q;
    q.push((node){x, 0});
    int res = 0;
    while (!q.empty())
    {
        node now = q.front();
        q.pop();
        for (int i = 1; i <= n; ++i)
        {
            if (g[now.u][i] && !v[i])
            {
                v[i] = 1;
                q.push((node){i, now.step + 1});
                res += num[i] * (now.step + 1);
            }
        }
    }
    return res;
}

void solve()
{
    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        int l = 0, r = 0;
        cin >> num[i] >> l >> r;
        if (l)
            g[l][i] = g[i][l] = 1;
        if (r)
            g[r][i] = g[i][r] = 1;
    }
    for (int i = 1; i <= n; ++i)
        ans = min(ans, bfs(i));
    cout << ans;
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    // freopen("./in.in", "r", stdin);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}