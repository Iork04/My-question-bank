#include <bits/stdc++.h>
#define i64 long long
using namespace std;
const int N = 1e6 + 10;
i64 input[N], lazy[N << 2], val[N << 2];
// Update current node.
inline void pushUp(i64 pos)
{
    val[pos] = val[pos << 1] + val[pos << 1 | 1];
}
inline void pushDown(i64 pos, i64 left, i64 right)
{
    if (lazy[pos])
    {
        i64 mid = (left + right) >> 1;
        lazy[pos << 1] += lazy[pos], lazy[pos << 1 | 1] += lazy[pos];
        val[pos << 1] += lazy[pos] * (mid - left + 1), val[pos << 1 | 1] += lazy[pos] * (right - mid);
        lazy[pos] = 0;
    }
}
// Build Segment tree.
void buildTree(i64 pos, i64 left, i64 right)
{
    lazy[pos] = 0;
    if (left == right)
    {
        val[pos] = input[left];
        return;
    }
    i64 mid = (left + right) >> 1;
    buildTree(pos << 1, left, mid);
    buildTree(pos << 1 | 1, mid + 1, right);
    pushUp(pos);
}
// Interval update.
void update(i64 pos, i64 left, i64 right, i64 _left, i64 _right, i64 _val)
{
    if (_left <= left && right <= _right)
    {
        val[pos] += (right - left + 1) * _val;
        lazy[pos] += _val;
        return;
    }
    pushDown(pos, left, right);
    i64 mid = (left + right) >> 1;
    if (mid >= _left)
        update(pos << 1, left, mid, _left, _right, _val);
    if (mid < _right)
        update(pos << 1 | 1, mid + 1, right, _left, _right, _val);
    pushUp(pos);
}
// Ask for the sum of interval values.
i64 ask(i64 left, i64 right, i64 _left, i64 _right, i64 pos)
{
    if (_left <= left && right <= _right)
        return val[pos];
    i64 res = 0, mid = (left + right) >> 1;
    pushDown(pos, left, right);
    if (_left <= mid)
        res += ask(left, mid, _left, _right, pos << 1);
    if (_right > mid)
        res += ask(mid + 1, right, _left, _right, pos << 1 | 1);
    return res;
}
// Print each value in the interval.
void printTree(i64 pos, i64 left, i64 right)
{
    if (left == right)
    {
        cout << val[pos] << " ";
        return;
    }
    pushDown(pos, left, right);
    i64 mid = (left + right) >> 1;
    printTree(pos << 1, left, mid);
    printTree(pos << 1 | 1, mid + 1, right);
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    i64 n, m, op, x, y, k;
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
            update(1, 1, n, x, y, k);
            break;
        case 2:
            cin >> x >> y;
            cout << ask(1, n, x, y, 1) << "\n";
            break;
        case 3:
            printTree(1, 1, n);
            cout << "\n";
            break;
        default:
            break;
        }
    }
    return 0;
}