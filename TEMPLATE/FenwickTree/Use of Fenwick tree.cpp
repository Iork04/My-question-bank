#include <bits/stdc++.h>
#define i64 long long
using namespace std;
class FenwickTree
{
private:
    vector<i64> BIT;
    i64 size;

public:
    FenwickTree(int _size)
    {
        BIT.assign(_size + 1, 0);
        size = _size;
    }

    void update(i64 index, i64 _val)
    {
        while (index <= size)
        {
            BIT[index] += _val;
            index += (index & -index);
        }
    }

    i64 query(i64 index)
    {
        i64 sum = 0;
        while (index > 0)
        {
            sum += BIT[index];
            index -= (index & -index);
        }
        return sum;
    }
    i64 getVal(i64 index)
    {
        return query(index) - query(index - 1);
    }
};
// Interval modification and interval query.
i64 getVal1(FenwickTree &a, FenwickTree &b, FenwickTree &sum, i64 l, i64 r)
{
    return (sum.query(r) + (r + 1) * a.query(r) - b.query(r)) - (sum.query(l - 1) + l * a.query(l - 1) - b.query(l - 1));
}
void solve1()
{
    i64 n;
    cin >> n;
    i64 arr[n + 1];
    FenwickTree sum(n), a(n), b(n);
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
        sum.update(i, arr[i]);
    }
    i64 l = 2, r = n - 1, val = 100;
    a.update(l, val);
    a.update(r + 1, -val);
    b.update(l, l * val);
    b.update(r + 1, -(r + 1) * val);
    cout << getVal1(a, b, sum, 1, n) << " ";
    cout << "\n";
    for (int i = 1; i <= n; ++i)
    {
        cout << getVal1(a, b, sum, i, i) << " ";
    }
}
// Interval modification and single point query.
i64 getVal2(FenwickTree &d, i64 arr[], i64 index)
{
    return arr[index] + d.query(index);
}
void solve2()
{
    i64 n;
    cin >> n;
    i64 arr[n + 1];
    FenwickTree d(n);
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    i64 l = 2, r = n - 1, val = 100;
    d.update(l, val);
    d.update(r + 1, -val);
    for (int i = 1; i <= n; ++i)
        cout << getVal2(d, arr, i) << " ";
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    solve1();
    return 0;
}