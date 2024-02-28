// https://www.luogu.com.cn/problem/P1621
// 并查集、质数筛
#include <bits/stdc++.h>
using namespace std;
int a, b, c, p[100100], ans;
bool prime[100100];

int find(int a)
{
    return a == p[a] ? a : p[a] = find(p[a]);
}

void getPrime()
{
    memset(prime, 1, sizeof(prime));
    prime[2] = 1;
    for (int i = 2; i <= b; ++i)
    {
        if (prime[i])
        {
            if (i >= c)
            {
                for (int j = i * 2; j <= b; j += i)
                {
                    prime[j] = 0;
                    if (j - i >= a && find(j) != find(j - i))
                    {
                        // cout << j - i << " " << j << "\n";
                        ans--;
                        p[find(j)] = find(j - i);
                    }
                }
            }
            else
            {
                for (int j = i * 2; j <= b; j += i)
                    prime[j] = 0;
            }
        }
    }
}

void solve()
{
    cin >> a >> b >> c;
    ans = b - a + 1;
    for (int i = a; i <= b; ++i)
        p[i] = i;
    getPrime();
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    // freopen("./in.in", "r", stdin);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}