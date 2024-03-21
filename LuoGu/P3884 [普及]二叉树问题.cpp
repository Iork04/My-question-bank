// https://www.luogu.com.cn/problem/P3884
// bfs、dfs
#include <bits/stdc++.h>
using namespace std;
bool v[105];
struct node
{
    int f, l, r;
} a[105];
int n;
int s, e, ans = 0;

int getDepth(int cur)
{
    if (cur == 0)
        return 0;
    return 1 + max(getDepth(a[cur].l), getDepth(a[cur].r));
}

int bfs(int x)
{
    queue<i64<int, int>> q;
    v[x] = 1;
    v[0] = 1;
    q.push({x, 0});
    bool flag = 1;
    while (!q.empty())
    {
        auto now = q.front();
        q.pop();
        // cout << now.first << " " << now.second << "\n";

        if (now.first == e)
            return now.second;

        if (!v[a[now.first].f])
        {
            v[a[now.first].f] = 1;
            q.push({a[now.first].f, now.second + 2});
        }
        if (!v[a[now.first].l])
        {
            v[a[now.first].l] = 1;
            q.push({a[now.first].l, now.second + 1});
        }
        if (!v[a[now.first].r])
        {
            v[a[now.first].r] = 1;
            q.push({a[now.first].r, now.second + 1});
        }
    }
    return -1;
}

int getW()
{
    int res = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int size = q.size();

        res = max(res, size);
        while (size--)
        {
            int now = q.front();
            q.pop();
            if (a[now].l)
                q.push(a[now].l);
            if (a[now].r)
                q.push(a[now].r);
        }
    }
    return res;
}

void solve()
{
    cin >> n;
    for (int i = 1; i < n; ++i)
    {
        int v1, v2;
        cin >> v1 >> v2;
        a[v2].f = v1;
        if (!a[v1].l)
            a[v1].l = v2;
        else
            a[v1].r = v2;
    }
    cin >> s >> e;
    // for (int i = 1; i <= n; ++i)
    //     cout << a[i].f << " " << a[i].l << " " << a[i].r << "\n";
    getW();
    cout << getDepth(1) << "\n"
         << getW() << "\n"
         << bfs(s);
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    freopen("./in.in", "r", stdin);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}