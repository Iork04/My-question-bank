// https://www.luogu.com.cn/problem/P2853
// 图论、dfs、贪心
#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int cur[105];
vector<int> a[1005];
int ans[1005];
bool _m[1005];

void dfs(int x)
{
    if (_m[x])
        return;
    _m[x] = 1;
    ans[x]++;
    for (int &val : a[x])
        dfs(val);
}

void solve()
{
    int res = 0;
    cin >> k >> n >> m;
    for (int i = 1; i <= k; ++i)
        cin >> cur[i];
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
    }
    for (int i = 1; i <= k; ++i)
    {
        for (int j = 1; j <= n; ++j)
            _m[j] = 0;
        dfs(cur[i]);
    }
    for (int i = 1; i <= n; ++i)
        if (k == ans[i])
            res++;
    cout << res;
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