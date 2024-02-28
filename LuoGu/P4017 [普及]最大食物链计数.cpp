// https://www.luogu.com.cn/problem/P4017
// 图论、拓扑排序
#include <bits/stdc++.h>
using namespace std;

int n, m, mod = 80112002, x, y, ans;
vector<int> a[5010];
vector<int> num(5010);
vector<int> in(5010), out(5010);
queue<int> q;
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >> x >> y;
        a[x].push_back(y);
        out[x]++, in[y]++;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!in[i])
        {
            num[i] = 1;
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < a[cur].size(); ++i)
        {
            int next = a[cur][i];
            --in[next];
            num[next] = (num[next] + num[cur]) % mod;
            if (!in[next])
                q.push(next);
        }
    }
    for (int i = 1; i <= n; ++i)
        if (!out[i])
            ans = (ans + num[i]) % mod;
    cout << ans;
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