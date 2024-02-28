// https://www.luogu.com.cn/problem/P1955
// 并查集、离散化、hash
#include <bits/stdc++.h>
using namespace std;
int n, i, j, e, tot, r1, r2;
struct node
{
    int i, j, e;
} a[100010];
int book[200020], f[200010];

void init(int size)
{
    for (int i = 1; i <= size; ++i)
        f[i] = i;
}

int find(int x)
{
    return x == f[x] ? x : f[x] = find(f[x]);
}

void Union(int a, int b)
{
    f[find(a)] = find(b);
}

bool cmp(node &a, node &b)
{
    return a.e > b.e;
}

void solve()
{
    bool flag = 1;
    cin >> n;
    tot = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].i >> a[i].j >> a[i].e;
        book[tot++] = a[i].i;
        book[tot++] = a[i].j;
    }
    sort(book, book + tot);
    int reu = unique(book, book + tot) - book;
    for (int i = 1; i <= n; ++i)
    {
        a[i].i = lower_bound(book, book + reu, a[i].i) - book + 1;
        a[i].j = lower_bound(book, book + reu, a[i].j) - book + 1;
    }
    sort(a + 1, a + 1 + n, cmp);
    init(reu);
    for (int i = 1; i <= n; ++i)
    {

        r1 = find(a[i].i);
        r2 = find(a[i].j);
        if (a[i].e)
        {
            Union(a[i].i, a[i].j);
        }
        else if (r1 == r2)
        {
            // cout << a[i].i << " " << a[i].j << "\n";
            // cout << find(a[i].i) << " " << find(a[i].j) << "\n";
            flag = 0;
            break;
        }
    }

    if (flag)
        cout << "YES\n";
    else
        cout << "NO\n";

    return;
}

int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    // freopen("./in.in", "r", stdin);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}