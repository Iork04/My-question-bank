#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
// https : // www.lanqiao.cn/problems/5131/learning/
struct Node
{
    int s, e, id, op;
} node[N];
int n, q;
int d[N], tr[N], res[N];
int lowbit(int x)
{
    return x & -x;
}
void add(int x, int c)
{
    for (int i = x; i < N; i += lowbit(i))
        tr[i] += c;
}
int sum(int x)
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += tr[i];
    return res;
}
bool cmp(const Node &a, const Node &b)
{
    if (a.e == b.e)
    {
        if (a.s != b.s)
            return a.s < b.s;
        return a.op < b.op;
    }
    return a.e > b.e;
}
void solve()
{
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        if (l > r)
            swap(l, r);
        d[l]++, d[r + 1]--;
        node[i] = {l, r, 0, 0};
    }
    for (int i = 1; i < N; i++)
        d[i] += d[i - 1];
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        res[i] = d[a];
        if (a > b)
            swap(a, b);
        node[n++] = {a, b, i, 1};
    }
    sort(node, node + n, cmp);
    for (int i = 0; i < n; i++)
    {
        if (node[i].op == 0)
            add(node[i].s, 1);
        else
            res[node[i].id] -= sum(node[i].s);
    }
    for (int i = 0; i < q; i++)
        cout << res[i] << "\n";
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
    return 0;
}