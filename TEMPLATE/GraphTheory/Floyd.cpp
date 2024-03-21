// https://www.luogu.com.cn/record/151201949
#include <bits/stdc++.h>
using namespace std;
const int M = 5000;
const int N = 150;

int u[M], v[M], w[M];
int e[N][N];
int n, m;

const int INF = 0x3f3f3f3f;

void solve()
{

    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            if (i == j)
                e[i][j] = 0;
            else
                e[i][j] = INF;
        }
    for (int i = 1; i <= m; ++i)
    {
        cin >> u[i] >> v[i] >> w[i];
        e[u[i]][v[i]] = min(w[i], e[u[i]][v[i]]);
        e[v[i]][u[i]] = min(w[i], e[v[i]][u[i]]);
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            for (int k = 1; k <= n; ++k)
            {
                // 如果对边为负值的话必须加上这一句
                if (j == i || i == k)
                    continue;
                e[j][k] = min(e[j][k], e[j][i] + e[i][k]);
            }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cout << e[i][j] << " ";
        cout << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int _ = 1;
    while (_--)
        solve();
}