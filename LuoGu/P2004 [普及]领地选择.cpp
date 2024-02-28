// https://www.luogu.com.cn/problem/P2004
// 前缀和
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N, M, C, x, y, ans = -1e9;
    cin >> N >> M >> C;
    int a[N + 1][M + 1];
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
        {
            cin >> a[i][j];
            a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + a[i][j];
        }

    for (int i = 0; i + C <= N; ++i)
        for (int j = 0; j + C <= M; ++j)
        {
            int now = a[i + C][j + C] + a[i][j] - a[i + C][j] - a[i][j + C];
            if (now > ans)
            {
                x = i + 1, y = j + 1;
                ans = now;
            }
        }
    cout << x << " " << y << "\n";
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