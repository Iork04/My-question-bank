// https://www.luogu.com.cn/problem/P5076
// AVL、BST
#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 10;
struct node
{
    int v, l, r, cnt, siz;
} tree[N];
int tot = 0, start = 0;
void add(int v)
{
    if (!tot)
    {
        start = ++tot;
        tree[tot].cnt = tree[tot].siz = 1;
        tree[tot].v = v;
        return;
    }
    int root = start, last = 0;
    do
    {
        ++tree[root].siz;
        if (tree[root].v == v)
        {
            ++tree[root].cnt;
            return;
        }
        last = root;
        if (tree[root].v > v)
        {
            root = tree[root].l;
            if (!root)
            {
                tree[last].l = ++tot;
                tree[tot].cnt = tree[tot].siz = 1;
                tree[tot].v = v;
                return;
            }
        }
        else
        {
            root = tree[root].r;
            if (!root)
            {
                tree[last].r = ++tot;
                tree[tot].cnt = tree[tot].siz = 1;
                tree[tot].v = v;
                return;
            }
        }
    } while (true);
}

int queryfr(int v)
{
    int res = -0x7fffffff, root = start;
    do
    {
        if (root == 0)
            return res;
        if (tree[root].v >= v)
            root = tree[root].l;
        else
        {
            res = tree[root].v;
            root = tree[root].r;
        }
    } while (true);
}

int queryne(int v)
{
    int res = 0x7fffffff, root = start;
    do
    {
        if (root == 0)
            return res;
        if (tree[root].v <= v)
            root = tree[root].r;
        else
        {
            res = tree[root].v;
            root = tree[root].l;
        }
    } while (true);
}

int queryval(int v)
{
    int root = start, res = 0;
    do
    {
        if (root == 0)
            return res;
        if (tree[root].v == v)
            return res + tree[tree[root].l].siz;
        else if (tree[root].v > v)
            root = tree[root].l;
        else
            res += tree[tree[root].l].siz + tree[root].cnt, root = tree[root].r;
    } while (true);
}

int queryrk(int k)
{
    int root = start;
    do
    {
        if (root == 0)
            return 0x7fffffff;
        if (tree[tree[root].l].siz >= k)
            root = tree[root].l;
        else if (tree[tree[root].l].siz + tree[root].cnt >= k)
            return tree[root].v;
        else
            k -= tree[tree[root].l].siz + tree[root].cnt, root = tree[root].r;
    } while (true);
}

void solve()
{
    int n;
    cin >> n;
    while (n--)
    {
        int op, x;
        cin >> op;
        switch (op)
        {
        case 1:
            cin >> x;
            cout << queryval(x) + 1 << "\n";
            break;
        case 2:
            cin >> x;
            cout << queryrk(x) << "\n";
            break;
        case 3:
            cin >> x;
            cout << queryfr(x) << "\n";
            break;
        case 4:
            cin >> x;
            cout << queryne(x) << "\n";
            break;
        case 5:
            cin >> x;
            add(x);
            break;
        default:
            break;
        }
    }
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