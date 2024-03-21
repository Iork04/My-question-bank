#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int n;
int t[N], d[N], l[N];
bool flag = 0, vis[N];

void dfs(int _count, int last)
{
    if (_count == n)
        flag = 1;
    if (flag)
        return;

    for (int i = 1; i <= n; ++i)
    {
        if (!vis[i])
        {
            if (last <= t[i] + d[i])
            {
                vis[i] = 1;
                if (last <= t[i])
                    dfs(_count + 1, t[i] + l[i]);
                else
                    dfs(_count + 1, last + l[i]);
                vis[i] = 0;
            }
            else
                return;
        }
    }
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> t[i] >> d[i] >> l[i];
    flag = 0;
    dfs(0, 0);
    if (flag)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
}