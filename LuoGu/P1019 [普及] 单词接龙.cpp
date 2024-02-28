// https://www.luogu.com.cn/problem/P1019
// 搜索、字符串
#include <bits/stdc++.h>
using namespace std;
int n, ans = 0;

vector<string> a(21);
int _a[21];

int check(string &a, string &b)
{
    for (int i = a.size() - 1; i >= 0 && a.size() - i <= b.size(); --i)
    {
        if (a[i] == b[0])
        {
            for (int j = i, k = 0; j <= a.size(); ++j, ++k)
            {
                if (j == a.size())
                    return a.size() - i;
                if (a[j] != b[k])
                    break;
            }
        }
    }
    return 0;
}

void dfs(int cur, int tot)
{
    ans = max(tot, ans);
    for (int i = 1; i <= n; ++i)
    {
        if (_a[i] < 2)
        {
            int val = check(a[cur], a[i]);
            // cout << a[cur] << " " << a[i] << " " << val << "\n";
            if (val)
            {
                ++_a[i];
                dfs(i, tot + a[i].size() - val);
                --_a[i];
            }
        }
    }
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    cin >> a[0];
    dfs(0, 1);
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