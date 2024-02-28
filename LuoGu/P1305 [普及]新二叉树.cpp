// https://www.luogu.com.cn/problem/P1305
// 模拟、递归
#include <bits/stdc++.h>
using namespace std;
int n;
vector<string> s;

void func(string &cur)
{
    cout << cur[0];
    if (cur[1] == '*' && cur[2] == '*')
        return;

    int l = 0, r = 0;
    for (int i = 1; i < n; ++i)
    {
        if (s[i][0] == cur[1])
            l = i;
        if (s[i][0] == cur[2])
            r = i;
    }
    if (cur[1] != '*')
        func(s[l]);
    if (cur[2] != '*')
        func(s[r]);
}

void solve()
{
    cin >> n;
    s.assign(n, " ");
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    func(s[0]);
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