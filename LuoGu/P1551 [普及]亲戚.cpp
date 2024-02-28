// https://www.luogu.com.cn/problem/P1551
// 并查集
#include <bits/stdc++.h>
using namespace std;
int pr[5010];
int n, m, p;

void initialize()
{
    for (int i = 1; i <= n; ++i)
        pr[i] = i;
}

int find(int x)
{
    if (x == pr[x])
        return x;
    return find(pr[x]);
}

void unios(int x, int y)
{
    int rootx = find(x), rooty = find(y);
    if (rootx != rooty)
        pr[rootx] = rooty;
}

void solve()
{
    cin >> n >> m >> p;
    initialize();
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        unios(x, y);
    }
    while (p--)
    {
        int x, y;
        cin >> x >> y;
        if (find(x) == find(y))
            cout << "Yes\n";
        else
            cout << "No\n";
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