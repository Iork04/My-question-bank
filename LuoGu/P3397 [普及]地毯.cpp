// https://www.luogu.com.cn/problem/P3397
// 前缀和
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    int x1, x2, y1, y2;
    cin >> n >> m;
    int a[n + 2][n + 2];
    memset(a, 0, sizeof(a));
    while (m--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        a[x1][y1] += 1;
        a[x2 + 1][y1] -= 1;
        a[x1][y2 + 1] -= 1;
        a[x2 + 1][y2 + 1] += 1;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + a[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cout << a[i][j] << (j == n ? "\n" : " ");
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