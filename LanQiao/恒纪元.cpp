#include <bits/stdc++.h>
using namespace std;
#define i64 long long
const i64 N = 1e12;
i64 x, y, z, q, now, ans;
set<i64> ljy;
bool _ljy[45][45][45];
void dfs(int a, int b, int c)
{
    _ljy[a][b][c] = 1;
    i64 tmp = pow(x, a) + pow(y, b) + pow(z, c);
    if (tmp > N)
        return;
    ljy.insert(tmp);
    if (x != 1 && !_ljy[a + 1][b][c])
        dfs(a + 1, b, c);
    if (y != 1 && !_ljy[a][b + 1][c])
        dfs(a, b + 1, c);
    if (z != 1 && !_ljy[a][b][c + 1])
        dfs(a, b, c + 1);
}

void solve()
{
    cin >> x >> y >> z >> q;
    dfs(0, 0, 0);
    // for (auto val : ljy)
    //     cout << val << " ";
    vector<i64> cs(ljy.begin(), ljy.end());
    while (q--)
    {
        cin >> now;
        i64 A, B;
        int it = lower_bound(cs.begin(), cs.end(), now) - cs.begin();
        while (it < cs.size() && cs[it] + 1 == cs[it + 1])
            ++it;
        A = cs[it] + 1;
        B = cs[it + 1] - A;
        cout << A << " " << B << "\n";
    }
}
int main()
{
    // ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    // freopen("./in.in", "r", stdin);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}