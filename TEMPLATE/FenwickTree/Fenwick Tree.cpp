#include <bits/stdc++.h>
using namespace std;
#define i64 long long
i64 n, m, op, x, y, k;
vector<i64> arr, tree;
// Single point modification.
void update(i64 index, i64 _val)
{
    while (index <= n)
    {
        tree[index] += _val;
        index += index & -index;
    }
}
// Sum up to the index element.
i64 query(i64 index)
{
    i64 sum = 0;
    while (index > 0)
    {
        sum += tree[index];
        index -= index & -index;
    }
    return sum;
}
i64 getVal(i64 index)
{
    return query(index) - query(index - 1);
}
int main()
{
    cin >> n >> m;
    arr.assign(n + 1, 0);
    tree.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
        update(i, arr[i]);
        cout << getVal(i) << " ";
    }
    cout << "\n";
    for (int i = 1; i <= n; ++i)
    {
        cout << query(i) << " ";
    }

    return 0;
}