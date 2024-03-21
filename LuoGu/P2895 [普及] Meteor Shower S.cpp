// https://www.luogu.com.cn/problem/P2895
// bfs、搜索、最短路、队列
#include <bits/stdc++.h>
using namespace std;
const int N = 302; // 边界
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};
vector<vector<int>> ans(310, vector<int>(310, -1));     // 到达时间
vector<vector<int>> m(310, vector<int>(310, 1e9 + 10)); // 地块最早被摧毁的时间

void bfs()
{
    queue<i64<int, int>> que;

    if (m[1][1] > 0)
    {
        que.push({1, 1});
        ans[1][1] = 0;
    }

    while (!que.empty())
    {
        i64<int, int> cur = que.front();
        que.pop();
        for (int i = 0; i < 4; ++i)
        {
            int nx = cur.first + dx[i], ny = cur.second + dy[i];
            if (nx > 0 && ny > 0 && nx <= N && ny <= N && ans[nx][ny] == -1 && m[nx][ny] > ans[cur.first][cur.second] + 1)
            {
                que.push({nx, ny});
                ans[nx][ny] = ans[cur.first][cur.second] + 1;
                if (m[nx][ny] == 1e9 + 10)
                {
                    cout << ans[nx][ny];
                    return;
                }
            }
        }
    }
    cout << "-1";
    return;
}

void solve()
{
    int n;
    cin >> n;

    while (n--)
    {
        int x, y, t;
        cin >> x >> y >> t;
        ++x, ++y; // 坐标偏移
        m[x][y] = min(m[x][y], t);
        for (int i = 0; i < 4; ++i)
            m[x + dx[i]][y + dy[i]] = min(t, m[x + dx[i]][y + dy[i]]);
    }

    // for (int i = 1; i <= 301; ++i)
    // {
    //     for (int j = 1; j <= 301; ++j)
    //         cout << setw(5) << (_p[i][j] == INT_MAX ? 0 : _p[i][j]);
    //     cout << "\n";
    // }

    bfs();
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