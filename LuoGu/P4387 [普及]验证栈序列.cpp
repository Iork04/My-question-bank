// https://www.luogu.com.cn/problem/P4387
// 栈
#include <bits/stdc++.h>
using namespace std;
int a[100010], b[100010], zhan[100010], top = 0;
void push(int v) { zhan[++top] = v; }
void pop() { --top; }
void solve()
{
    int q;
    cin >> q;
    while (q--)
    {
        int n, flag = 1, val, tb = 1;
        top = 0;
        cin >> n;
        bool _a[n + 1];
        memset(_a, 0, sizeof(_a));
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        for (int i = 1; i <= n; ++i)
            cin >> b[i];
        for (int i = 1; i <= n; ++i)
        {
            push(a[i]);
            while (top > 0 && zhan[top] == b[tb])
                ++tb, pop();
        }
        if (!top)
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