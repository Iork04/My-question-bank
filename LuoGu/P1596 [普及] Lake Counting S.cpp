// https://www.luogu.com.cn/problem/P1596
// DFS、搜索
#include <bits/stdc++.h>
using namespace std;

char m[150][150];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int ans, N, M;

void dfs(int x, int y)
{
    if (m[x][y] != 'W')
        return;
    m[x][y] = '.';
    for (int i = 0; i < 8; ++i)
    {
        int newx = x + dx[i], newy = y + dy[i];
        dfs(newx, newy);
    }
}

void solve()
{
    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
            cin >> m[i][j];
    }
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            if (m[i][j] == 'W')
            {
                dfs(i, j);
                ++ans;
            }
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