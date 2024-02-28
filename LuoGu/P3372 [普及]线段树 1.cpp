#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 10;
ll input[N], lazy[N << 2], val[N << 2];
// Updata current node
inline void pushUp(ll pos)
{
    val[pos] = val[pos << 1] + val[pos << 1 | 1];
}
inline void pushDown(ll pos, ll left, ll right)
{
    if (lazy[pos])
    {
        ll mid = (left + right) >> 1;
        lazy[pos << 1] += lazy[pos], lazy[pos << 1 | 1] += lazy[pos];
        val[pos << 1] += lazy[pos] * (mid - left + 1), val[pos << 1 | 1] += lazy[pos] * (right - mid);
        lazy[pos] = 0;
    }
}
// Build Segment tree
void buildTree(ll pos, ll left, ll right)
{
    lazy[pos] = 0;
    if (left == right)
    {
        val[pos] = input[left];
        return;
    }
    ll mid = (left + right) >> 1;
    buildTree(pos << 1, left, mid);
    buildTree(pos << 1 | 1, mid + 1, right);
    pushUp(pos);
}
// Print each value in the interval
void printTree(ll pos, ll left, ll right)
{
    cout << left << " " << right << " " << val[pos] << "\n";
    if (left == right)
    {
        // cout << val[pos] << " ";
        return;
    }
    pushDown(pos, left, right);
    ll mid = (left + right) >> 1;
    printTree(pos << 1, left, mid);
    printTree(pos << 1 | 1, mid + 1, right);
}
// Interval updata
void upData(ll _left, ll _right, ll left, ll right, ll pos, ll _val)
{
    if (_left <= left && _right >= right)
    {
        val[pos] += _val * (right - left + 1);
        lazy[pos] += _val;
        return;
    }
    pushDown(pos, left, right);
    ll mid = (left + right) >> 1;
    if (_left <= mid)
        upData(_left, _right, left, mid, pos << 1, _val);
    if (_right > mid)
        upData(_left, _right, mid + 1, right, pos << 1 | 1, _val);
    pushUp(pos);
}
// Ask for the sum of interval values
ll ask(ll _left, ll _right, ll left, ll right, ll pos)
{
    if (_left <= left && right <= _right)
        return val[pos];
    ll res = 0, mid = (left + right) >> 1;
    pushDown(pos, left, right);
    if (_left <= mid)
        res += ask(_left, _right, left, mid, pos << 1);
    if (_right > mid)
        res += ask(_left, _right, mid + 1, right, pos << 1 | 1);
    return res;
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    ll n, m, op, x, y, k;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> input[i];
    buildTree(1, 1, n);
    while (m--)
    {
        cin >> op;
        switch (op)
        {
        case 1:
            cin >> x >> y >> k;
            upData(x, y, 1, n, 1, k);
            break;
        case 2:
            cin >> x >> y;
            cout << ask(x, y, 1, n, 1) << "\n";
            break;
        case 3:
            printTree(1, 1, n);
            break;
        default:
            break;
        }
    }
    return 0;
}