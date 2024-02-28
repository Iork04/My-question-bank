// https://www.luogu.com.cn/problem/P5937
// 离散化、并查集
#include <bits/stdc++.h>
using namespace std;
int n, m, sz = 0;
struct node
{
    int x, y, z;
} a[5010];

int f[20010];
int qy[20010];

int find(int x)
{
    return x == f[x] ? x : f[x] = find(f[x]);
}

void Union(int a, int b)
{
    int x = find(a);
    int y = find(b);
    if (x != y)
        f[x] = y;
}

void solve()
{
    cin >> n >> m;
    string str;
    unordered_map<int, int> q;
    int x, y;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a[i].x >> a[i].y >> str;
        a[i].x--;
        qy[++sz] = a[i].x;
        qy[++sz] = a[i].y;
        a[i].z = (str[0] == 'e');
    }
    sort(qy + 1, qy + 1 + sz);
    sz = unique(qy + 1, qy + 1 + sz) - qy - 1;
    for (int i = 1; i <= sz; ++i)
        q[qy[i]] = i;

    for (int i = 1; i <= 2 * sz; ++i)
        f[i] = i;

    // for (int i = 1; i <= m; ++i)
    //     cout << q[a[i].x] << " " << q[a[i].y] << " " << a[i].z << "\n";
    
    for (int i = 1; i <= m; ++i)
    {
        x = q[a[i].x];
        y = q[a[i].y];
        if (a[i].z)
        {
            if (find(x) == find(y + sz))
            {
                cout << i - 1;
                return;
            }
            else
            {
                Union(x, y);
                Union(x + sz, y + sz);
            }
        }
        else
        {
            if (find(x) == find(y))
            {
                cout << i - 1;
                return;
            }
            else
            {
                Union(x, y + sz);
                Union(x + sz, y);
            }
        }
    }
    cout << m;
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