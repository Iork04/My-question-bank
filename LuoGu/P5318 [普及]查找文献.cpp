// https://www.luogu.com.cn/problem/P5318
// 图论
#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int s, e;
} edges[1000010];

bool cmp(edge &a, edge &b)
{
    return a.e < b.e;
}
vector<int> a[100010];
bool _a[100010];
int m, n;

void dfs(int x)
{
    if (_a[x])
        return;
    cout << x << " ";
    _a[x] = 1;
    for (auto &val : a[x])
        dfs(val);
}

void bfs(int x)
{
    queue<int> que;
    memset(_a, 0, sizeof(_a));
    que.push(x);
    _a[x] = 1;
    while (!que.empty())
    {
        int cur = que.front();
        que.pop();
        cout << cur << " ";
        for (auto &val : a[cur])
        {
            if (_a[val])
                continue;
            que.push(val);
            _a[val] = 1;
        }
    }
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
        cin >> edges[i].s >> edges[i].e;
    sort(edges, edges + m, cmp);
    for (int i = 0; i < m; ++i)
        a[edges[i].s].push_back(edges[i].e);

    // for (int i = 1; i <= n; ++i)
    // {
    //     cout << i << ":";
    //     for (int j = 0; j < a[i].size(); ++j)
    //         cout << a[i][j] << " ";
    //     cout << "\n";
    // }
    dfs(1);
    cout << "\n";
    bfs(1);
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