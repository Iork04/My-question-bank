// https://www.luogu.com.cn/problem/P1443
// bfs、搜索、最短路、队列
#include <bits/stdc++.h>
using namespace std;
int n, m, sx, sy;
int p[500][500];
int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
void bfs(int x, int y)
{
    p[x][y] = 0;
    queue<i64<int, int>> que;
    que.push({x, y});
    while (!que.empty())
    {
        i64<int, int> cur = que.front();
        que.pop();
        for (int i = 0; i < 8; ++i)
        {
            int nx = cur.first + dx[i], ny = cur.second + dy[i];
            if (nx > 0 && nx <= n && ny > 0 && ny <= m && p[nx][ny] == -1)
            {
                p[nx][ny] = p[cur.first][cur.second] + 1;
                que.push({nx, ny});
            }
        }
    }
}
void solve()
{
    cin >> n >> m >> sx >> sy;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            p[i][j] = -1;
    bfs(sx, sy);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            cout << p[i][j] << " ";
        cout << "\n";
    }
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