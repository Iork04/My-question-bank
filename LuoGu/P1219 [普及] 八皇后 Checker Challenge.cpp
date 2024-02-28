// https://www.luogu.com.cn/problem/P1219
// DFS、搜索
#include <bits/stdc++.h>
using namespace std;
vector<bool> t1(100, true), t2(100, true), t3(100, true);
vector<vector<int>> result;
vector<int> path(20);
int n, _count = 0;
void dfs(int depth)
{
    if (depth > n)
    {
        if (result.size() != 3)
            result.push_back(path);
        ++_count;
        return;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (t1[i] && t2[i + depth] && t3[n - i + depth])
        {
            t1[i] = false, t2[i + depth] = false, t3[n - i + depth] = false;
            path[depth] = i;
            dfs(depth + 1);

            t1[i] = true, t2[i + depth] = true, t3[n - i + depth] = true;
        }
    }
}

void solve()
{
    cin >> n;
    dfs(1);
    for (auto p : result)
    {
        for (int i = 1; i <= n; ++i)
            cout << p[i] << " ";
        cout << "\n";
    }
    cout << _count;
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