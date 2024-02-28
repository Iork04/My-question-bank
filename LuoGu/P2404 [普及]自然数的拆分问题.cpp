// https://www.luogu.com.cn/problem/P2404
// DFS、搜索
#include <bits/stdc++.h>
using namespace std;
int target;
int path[100];
void _print(int size)
{
    for (int i = 1; i < size; ++i)
        cout << path[i] << "+";
    cout << path[size] << "\n";
}

void dfs(int depth, int now, int cur)
{
    if (now == target)
    {
        _print(depth - 1);
        return;
    }
    if (now > target)
        return;
    int m = target - cur;
    for (int i = cur; i <= m; ++i)
    {
        path[depth] = i;
        dfs(depth + 1, now + i, i);
    }
}

void solve()
{
    cin >> target;
    dfs(1, 0, 1);
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