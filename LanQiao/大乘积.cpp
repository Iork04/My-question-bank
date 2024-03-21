// https://www.lanqiao.cn/problems/2409/learning/?page=1&first_category_id=1&tags=2023
#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
vector<vector<char>> m(32, vector<char>(62, 0));
vector<vector<bool>> vis(32, vector<bool>(62, 0));

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int _count = 0;
int ans = 0;

void dfs(int x, int y)
{
    if (x < 1 || x > 30 || y < 1 || y > 60 || m[x][y] == '0' || vis[x][y])
        return;
    _count++;
    vis[x][y] = 1;
    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i], ny = y + dy[i];
        dfs(nx, ny);
    }
}

void solve()
{
    for (int i = 1; i <= 30; ++i)
        for (int j = 1; j <= 60; ++j)
            cin >> m[i][j];

    for (int i = 1; i <= 30; ++i)
        for (int j = 1; j <= 60; ++j)
            if (m[i][j] == '1')
            {
                _count = 0;
                dfs(i, j);
                ans = max(ans, _count);
            }

    cout << ans;
}

int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int _ = 0;
    while (_--)
        solve();
    cout << 148;
    return 0;
}
