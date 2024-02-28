// https://www.luogu.com.cn/problem/P1101
// DFS、搜索、字符串
#include <bits/stdc++.h>
using namespace std;
char m[101][101];
bool _m[101][101];
int dx[9] = {0, -1, -1, -1, 0, 0, 1, 1, 1};
int dy[9] = {0, -1, 0, 1, -1, 1, -1, 0, 1};
string str = " yizhong";
int n;
bool flag = false, t = false;
void dfs(int x, int y, int p, int now)
{
    if (now == 8)
    {
        flag = t = true;
        return;
    }

    if (x < 1 || x > n || y < 1 || y > n || m[x][y] != str[now])
        return;
    if (p == 0)
    {
        for (int i = 1; i <= 8; ++i)
        {
            int newx = x + dx[i], newy = y + dy[i];
            if (m[newx][newy] == str[now + 1])
            {
                dfs(newx, newy, i, now + 1);
                _m[x][y] = flag || _m[x][y];
                flag = false;
            }
        }
    }
    else
    {
        int newx = x + dx[p], newy = y + dy[p];
        dfs(newx, newy, p, now + 1);
        _m[x][y] = flag || _m[x][y];
    }
    return;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cin >> m[i][j];
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (m[i][j] == 'y')
            {
                flag = t = false;
                dfs(i, j, 0, 1);
                _m[i][j] = t;
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cout << (_m[i][j] ? m[i][j] : '*');
        }
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