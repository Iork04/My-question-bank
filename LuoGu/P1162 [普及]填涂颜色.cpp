// https://www.luogu.com.cn/problem/P1162
// DFS、搜索、队列
#include <bits/stdc++.h>
using namespace std;
int m[100][100], flag = 0;
bool _m[100][100];
int n;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
void dfs(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > n)
    {
        flag = 0;
        return;
    }
    if (m[x][y] == 1)
        return;
    for (int i = 0; i < 4; ++i)
    {
        int newx = x + dx[i], newy = y + dy[i];
        if (!_m[newx][newy])
        {
            _m[newx][newy] = 1;
            dfs(newx, newy);
        }
    }
    m[x][y] = flag;
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> m[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            if (!_m[i][j] && m[i][j] == 0)
            {
                // cout << i << " " << j << "\n";
                flag = 2;
                dfs(i, j);
            }
        }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cout << m[i][j] << " ";
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