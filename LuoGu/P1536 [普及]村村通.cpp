// https://www.luogu.com.cn/problem/P1536
// 并查集
#include <bits/stdc++.h>
using namespace std;
typedef long long i64;

int n, m;
int p[2000], rk[2000];

void initialize()
{
    memset(rk, 0, sizeof(rk));
    for (int i = 1; i <= n; ++i)
        p[i] = i;
}

int find(int x)
{
    // 路径压缩
    return x == p[x] ? x : p[x] = find(p[x]);
}

void unios(int a, int b)
{
    int _a = find(a);
    int _b = find(b);
    if (_a != _b)
    {
        if (rk[_a] < rk[_b])
            p[_a] = _b;
        else if (rk[_a] > rk[_b])
            p[_b] = _a;
        else
        {
            p[_a] = _b;
            rk[_b]++;
        }
    }
}

void solve()
{
    while (true)
    {
        cin >> n;
        if (n == 0)
            return;
        cin >> m;
        initialize();
        while (m--)
        {
            int a, b;
            cin >> a >> b;
            unios(a, b);
        }
        set<int> res;
        for (int i = 1; i <= n; ++i)
            res.insert(find(i));
        cout << res.size() - 1 << "\n";
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