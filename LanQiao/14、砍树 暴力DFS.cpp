#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef long long i64;
int w[N];
map<pair<int, int>, int> id;
vector<int> edge[N];

bool dfs(int s, int u, int f, int v)
{
    if (u == v)
        return true;
    for (int _v : edge[u])
    {
        if (f == _v)
            continue;
        if (dfs(s, _v, u, v))
        {
            int ID = id[{_v, u}];
            w[ID]++;
            return true;
        }
    }
    return false;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        edge[v].push_back(u);
        edge[u].push_back(v);
        id[{u, v}] = id[{v, u}] = i + 1;
    }
    int ans = -1;
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        dfs(u, u, -1, v);
    }
    for (int i = n - 1; i >= 0; --i)
    {
        // cout << w[i] << " ";
        if (w[i] >= m)
        {
            ans = i;
            break;
        }
    }
    // cout << "\n";
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}