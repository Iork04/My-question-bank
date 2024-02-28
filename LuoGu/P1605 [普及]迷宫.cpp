// https://www.luogu.com.cn/problem/P1605
// DFS、搜索、递推
#include <bits/stdc++.h>
using namespace std;
int N, M, T, sx, sy, fx, fy, _count;
bool m[10][10];
int path[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
void walk(int x, int y)
{
    if (x < 1 || x > M || y < 1 || y > N)
        return;
    // cout << x << " " << y << "\n";
    if (x == fx && y == fy)
    {
        _count++;
        return;
    }
    for (int i = 0; i < 4; ++i)
    {
        int newx = x + path[i][0], newy = y + path[i][1];
        if (m[newx][newy] == 0)
        {
            m[newx][newy] = 1;
            walk(newx, newy);
            m[newx][newy] = 0;
        }
    }
}
void solve()
{
    cin >> N >> M >> T;
    cin >> sx >> sy >> fx >> fy;
    int x, y;
    while (T--)
    {
        cin >> x >> y;
        m[x][y] = 1;
    }
    m[sx][sy] = true;
    walk(sx, sy);
    cout << _count;
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