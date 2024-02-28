// https://www.luogu.com.cn/problem/P1525
// 并查集、贪心
#include <bits/stdc++.h>
using namespace std;
int p[20005];
struct node
{
    int x, b, c;
} a[100010];
int b[20005];

bool cmp(struct node &a, struct node &b)
{
    return a.c > b.c;
}

int find(int a)
{
    return a == p[a] ? a : p[a] = find(p[a]);
}

void Union(int a, int b)
{
    int ra = find(a);
    int rb = find(b);
    p[ra] = rb;
}

bool check(int a, int b)
{
    return find(a) == find(b);
}

void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        p[i] = i;
    for (int i = 1; i <= q; ++i)
        cin >> a[i].x >> a[i].b >> a[i].c;
    sort(a + 1, a + 1 + q, cmp);
    for (int i = 1; i <= q + 1; ++i)
    {
        if (check(a[i].x, a[i].b))
        {
            cout << a[i].c;
            break;
        }
        else
        {
            if (!b[a[i].x])
                b[a[i].x] = a[i].b;
            else
                Union(b[a[i].x], a[i].b);

            if (!b[a[i].b])
                b[a[i].b] = a[i].x;
            else
                Union(b[a[i].b], a[i].x);
        }
    }
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