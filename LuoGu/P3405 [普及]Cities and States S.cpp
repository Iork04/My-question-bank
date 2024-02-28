// https://www.luogu.com.cn/problem/P3405
// map、hash
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string a, b, ca;
    int n, ans = 0;
    cin >> n;
    map<string, int> m;
    while (n--)
    {
        cin >> a >> b;
        ca = a.substr(0, 2);
        if (ca != b)
        {
            m[ca + b]++;
            ans += m[b + ca];
        }
    }
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