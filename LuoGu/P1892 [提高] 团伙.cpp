// https://www.luogu.com.cn/problem/P1621
// 并查集
#include <bits/stdc++.h>
using namespace std;

int p[3000];
int n, m;

int find(int a)
{
    return a == p[a] ? a : p[a] = find(p[a]);
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= 2 * n; ++i)
        p[i] = i;
    while (m--)
    {
        int a, b;
        char c;
        cin >> c >> a >> b;
        if (c == 'F')
        {
            p[find(a)] = find(b);
        }
        else
        {
            p[find(n + a)] = find(b);
            p[find(n + b)] = find(a);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += (i == p[i]);
    cout << ans;
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