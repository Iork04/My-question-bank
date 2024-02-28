// https://www.luogu.com.cn/problem/P1433
// DP、状态压缩
#include <bits/stdc++.h>
using namespace std;
int n;
double x[16], y[16], a[16][16], f[16][1 << 16];

double distance(int a, int b)
{
    return sqrt((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]));
}

void solve()
{
    memset(f, 127, sizeof(f));
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> x[i] >> y[i];
    for (int i = 0; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            a[i][j] = a[j][i] = distance(i, j);

    for (int i = 1; i <= n; ++i)
        f[i][1 << (i - 1)] = a[0][i];

    for (int k = 1; k < (1 << n); ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            if (k & (1 << (i - 1)))
            {
                for (int j = 1; j <= n; ++j)
                {
                    if (i == j)
                        continue;
                    if (k & (1 << (j - 1)))
                        f[i][k] = min(f[i][k], f[j][k - (1 << (i - 1))] + a[i][j]);
                }
            }
        }
    }
    double ans = f[0][0];
    for (int i = 1; i <= n; ++i)
        ans = min(ans, f[i][(1 << n) - 1]);
    cout << fixed << setprecision(2) << ans;
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    freopen("./in.in", "r", stdin);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}