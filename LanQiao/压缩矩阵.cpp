#include <bits/stdc++.h>
using namespace std;
#define i64 long long
i64 n, q;
pair<i64, i64> getB(i64 index)
{
    if (index <= 2)
        return {1, index};
    index -= 2;

    i64 i = ceil(index * 1.0 / 3)+1;
    i64 j;
    if (index % 3 == 0)
        j = 1;
    else if (index % 3 == 1)
        j = -1;
    else
        j = 0;

    return {i, i + j};
}

void solve()
{
    cin >> n >> q;
    while (q--)
    {
        i64 index;
        cin >> index;
        ++index;
        pair<i64, i64> cur = getB(index);
        cout << cur.first << " " << cur.second << "\n";
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