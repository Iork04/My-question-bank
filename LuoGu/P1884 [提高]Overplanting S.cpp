// https://www.luogu.com.cn/problem/P1884
// 离散化、线段树
#include <bits/stdc++.h>

using namespace std;
const int MAX = 2010 << 2;
const int N = 1010;
int n, m = 0;
long long ans = 0;

// 存边
struct node
{
    int x, s, e, v;
    bool operator<(const node &other) const
    {
        if (this->x == other.x)
            return this->v < other.v;
        return this->x < other.x;
    }
} a[N << 1];

int qy[N << 1];
unordered_map<int, int> H;

struct Segtree
{
    // 左右节点
#define i0 (i << 1)
#define i1 (i << 1 | 1)

    // v>0时区间被覆盖、len存储区间被覆盖长度
    int v[MAX], len[MAX], L[MAX], R[MAX];

    // 建树
    void build(int i, int l, int r)
    {
        v[i] = len[i] = 0;
        L[i] = l, R[i] = r;
        if (l != r)
        {
            int mid = (l + r) >> 1;
            build(i0, l, mid);
            build(i1, mid + 1, r);
        }
    }

    // 更新
    void upd(int i, int l, int r, int c)
    {
        if (r < L[i] || R[i] < l)
            return;

        if (l <= L[i] && R[i] <= r)
            v[i] += c;
        else
            upd(i0, l, r, c), upd(i1, l, r, c);

        // 如果被覆盖则更新长度
        if (v[i])
        {
            len[i] = abs(qy[R[i] + 1] - qy[L[i]]);
        }
        else
        {
            if (L[i] == R[i])
                len[i] = 0;
            else
                len[i] = len[i0] + len[i1];
        }
        // cout << "*" << i << " " << L[i] << " " << R[i] << " " << v[i] << " " << len[i] << "\n";
    }
} tree;

void solve()
{
    cin >> n;
    for (int i = 1, x1, y1, x2, y2; i <= n; ++i)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        a[i] = node{x1, y2, y1, 1};
        a[i + n] = node{x2, y2, y1, -1};
        qy[++m] = y1, qy[++m] = y2;
    }
    n <<= 1;
    sort(qy + 1, qy + m + 1);
    sort(a + 1, a + 1 + n); // 对x排序
    m = unique(qy + 1, qy + 1 + m) - qy - 1;
    // 离散
    for (int i = 1; i <= m; ++i)
        H[qy[i]] = i;
    tree.build(1, 1, n);
    for (int i = 1; i <= n; ++i)
    {
        tree.upd(1, H[a[i].s], H[a[i].e] - 1, a[i].v);                       // 更新覆盖
        ans += (long long)tree.len[1] * (long long)abs(a[i + 1].x - a[i].x); // 累加区间面积
        // cout << H[a[i].s] << " " << H[a[i].e] << " " << a[i].d << " " << (long long)Seg.len[1] << " " << ans << "\n";
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    freopen("./in.in", "r", stdin);
    int _ = 1;
    // cin >> _;
    while (_--)
        solve();
    return 0;
}