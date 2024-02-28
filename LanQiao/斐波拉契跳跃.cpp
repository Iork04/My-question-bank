#include <bits/stdc++.h>
using namespace std;
// https://www.lanqiao.cn/problems/8051/learning/?contest_id=146
const int N = 1e5 + 10;
int f[30], a[N], m, n;
vector<vector<int>> sg(N, vector<int>(30, -1));
void init()
{
    f[0] = 0, f[1] = 1, f[2] = 2;
    for (int i = 3;; ++i)
    {
        f[i] = f[i - 1] + f[i - 2];
        if (f[i] >= 100000)
        {
            m = i - 1;
            // cout << m;
            break;
        }
    }
}
int dfs(int x, int l)
{
    if (sg[x][l] != -1)
        return sg[x][l];
    int flag = 0;
    for (int i = 0; i <= m; ++i)
    {
        int v = f[i];
        if (x - v >= 1 && a[x - v] > a[x] && i > l)
        {
            dfs(x - v, i);
            flag = flag || !sg[x - v][i];
        }
        if (x + v <= n && a[x + v] > a[x] && i > l)
        {
            dfs(x + v, i);
            flag = flag || !sg[x + v][i];
        }
    }
    sg[x][l] = flag;
    return flag;
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    init();
    // freopen("in.in", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
    {
        if (dfs(i, 0) == 0)
            cout << "Little Qiao\n";
        else
            cout << "Little Lan\n";
    }
    return 0;
}