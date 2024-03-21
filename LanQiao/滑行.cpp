// https://www.lanqiao.cn/problems/2414/learning/?page=1&first_category_id=1&tags=2023
#include <bits/stdc++.h>
using namespace std;
typedef long long i64;

int _map[105][105];
int n, m;
int _count[105][105];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int dfs(int x, int y)
{
    if (_count[x][y])
        return _count[x][y];
    int cur = _map[x][y];
    _count[x][y] = 1;
    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 1 || nx > n || ny < 1 || ny > m || _map[nx][ny] >= cur)
            continue;
        _count[x][y] = max(_count[x][y], dfs(nx, ny) + 1);
    }

    return _count[x][y];
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> _map[i][j];

    int ans = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            ans = max(dfs(i, j), ans);
        }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}