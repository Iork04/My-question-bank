// https://www.luogu.com.cn/problem/P1185
// 绘图
#include <bits/stdc++.h>
using namespace std;
int k, n, m, p, x, y;
bool f[800][1600];
char c[800][1600];

void dfs(int x, int y, int a, int b, int k, int xx, int yy)
{
    if (x == n)
    {
        c[x][y] = 'o';
        return;
    }
    if (k == 1)
    {
        int X, Y;
        c[x][y] = 'o';
        X = xx + 1, Y = yy * 2 - 1;
        if (!f[X][Y])
            dfs(x + 1, y - 1, a + 1, b, 2, X, Y);
        X = xx + 1, Y = yy * 2;
        if (!f[X][Y])
            dfs(x + 1, y + 1, a + 1, b, 3, X, Y);
    }
    else if (k == 2)
    {
        c[x][y] = '/';
        if ((a << 1) == b)
            dfs(x + 1, y - 1, 1, b >> 1, 1, xx, yy);
        else
            dfs(x + 1, y - 1, a + 1, b, 2, xx, yy);
    }
    else if (k == 3)
    {
        c[x][y] = 92;
        if ((a << 1) == b)
            dfs(x + 1, y + 1, 1, b >> 1, 1, xx, yy);
        else
            dfs(x + 1, y + 1, a + 1, b, 3, xx, yy);
    }
}

void make(int k)
{
    n = 3;
    for (int i = 3; i <= k; ++i)
        n <<= 1;
    m = 6 * (1 << (k - 2)) - 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            c[i][j] = ' ';
    dfs(1, m / 2 + 1, 1, n, 1, 1, 1);
}

void solve()
{
    cin >> k >> p;
    while (p--)
    {
        int i, j;
        cin >> i >> j;
        f[i][j] = 1;
    }
    if (k == 1)
        n = m = 1, c[1][1] = 'o';
    else
        make(k);
    // cout << m << " " << n<<"\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << c[i][j];
        cout << endl;
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