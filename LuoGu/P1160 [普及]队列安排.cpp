// https://www.luogu.com.cn/problem/P1160
// 模拟、构造
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct T
{
    int val, l, r, d;
} t[N];
void add(int i, int k, int op)
{
    if (op)
    {
        t[k].l = i;
        t[k].r = t[i].r;
        t[i].r = k;
        t[t[k].r].l = k;
    }
    else
    {
        t[k].r = i;
        t[k].l = t[i].l;
        t[i].l = k;
        t[t[k].l].r = k;
    }
}
void solve()
{
    int m, n;
    cin >> n;
    for (int i = 2; i <= n; ++i)
    {
        int val, op;
        cin >> val >> op;
        add(val, i, op);
    }
    cin >> m;
    while (m--)
    {
        int val;
        cin >> val;
        t[val].d = 1;
    }
    for (int i = t[0].r; i; i = t[i].r)
        if (!t[i].d)
            cout << i << " ";
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