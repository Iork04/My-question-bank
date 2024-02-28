// https://www.luogu.com.cn/problem/P1801
// 堆
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
typedef long long i64;
void solve()
{
    int n, m;
    cin >> m >> n;
    int a[m + 1], b[n + 1];
    for (int i = 1; i <= m; ++i)
    {
        cin >> a[i];
        // cout << a[i] << " ";
    }
    // cout << "\n";
    for (int i = 1; i <= n; ++i)
    {
        cin >> b[i];
        // cout << b[i] << " ";
    }
    // cout << "\n";
    priority_queue<int, vector<int>, less<int>> ma;
    priority_queue<int, vector<int>, greater<int>> mi;
    int now = 0;
    for (int i = 1; i <= n; ++i)
    {
        while (now < b[i])
        {
            ++now;
            ma.push(a[now]);
            mi.push(ma.top());
            ma.pop();
        }
        cout << mi.top() << "\n";
        ma.push(mi.top());
        mi.pop();
    }
}

int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    // freopen("./in.in", "r", stdin);
    int _ = 1;
    // cin >> _;
    while (_--)
        solve();
    return 0;
}