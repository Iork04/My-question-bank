// https://www.luogu.com.cn/problem/P1363
// 图论、dfs
#include <bits/stdc++.h>
using namespace std;
int n, m, sx, sy;
int dx[] = {0, 1, -1, 0};
int dy[] = {-1, 0, 0, 1};
bool mp[1500][1500];
int vis[1500][1500][3];
char ch;
bool flag = 0;

void dfs(int x, int y, int lx, int ly)
{
    if (flag)
        return;
    if (vis[x][y][0] && (vis[x][y][1] != lx || vis[x][y][2] != ly))
    {
        flag = 1;
        return;
    }
    vis[x][y][0] = 1, vis[x][y][1] = lx, vis[x][y][2] = ly;
    for (int i = 0; i < 4; ++i)
    {
        int nx = (x + dx[i] + n) % n, ny = (y + dy[i] + m) % m;
        int nlx = lx + dx[i], nly = ly + dy[i];
        if (!mp[nx][ny])
            if (!vis[nx][ny][0] || vis[nx][ny][1] != nlx || vis[nx][ny][2] != nly)
                dfs(nx, ny, nlx, nly);
    }
}

void solve()
{
    while (cin >> n >> m)
    {
        memset(vis, 0, sizeof(vis));
        memset(mp, 0, sizeof(mp));
        flag = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin >> ch;
                if (ch == 'S')
                    sx = i, sy = j;
                if (ch == '#')
                    mp[i][j] = 1;
            }
        }
        dfs(sx, sy, sx, sy);
        if (flag)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}

int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    freopen("./in.in", "r", stdin);
    int _ = 1;
    // cin >> _;
    while (_--)
        solve();
    return 0;
}