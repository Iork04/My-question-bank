// https://www.luogu.com.cn/problem/P1135
// bfs、搜索、最短路、队列
#include <bits/stdc++.h>
using namespace std;
int h, s, e, w[300], ans[300];

void bfs(int a)
{
    queue<int> que;
    int next;
    ans[a] = 0;
    que.push(a);
    while (!que.empty())
    {
        int cur = que.front();
        que.pop();
        next = cur + w[cur];
        if (next > 0 && next <= h && ans[next] == -1)
        {
            que.push(next);
            ans[next] = ans[cur] + 1;
        }
        next = cur - w[cur];
        if (next > 0 && next <= h && ans[next] == -1)
        {
            que.push(next);
            ans[next] = ans[cur] + 1;
        }
        if (ans[e] != -1)
            return;
    }
}

void solve()
{
    cin >> h >> s >> e;
    for (int i = 1; i <= h; ++i)
    {
        cin >> w[i];
        ans[i] = -1;
    }
    bfs(s);
    cout << ans[e];
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