#include <bits/stdc++.h>
using namespace std;
typedef long long i64;

void solve()
{
    int n = 26 * 26 + 26;
    for (char i = 'A'; i <= 'Z'; ++i)
    {
        for (char j = 'A'; j <= 'Z'; ++j)
        {
            for (char k = 'A'; k <= 'Z'; ++k)
            {
                n++;
                if (n == 2022)
                {
                    cout << i << j << k;
                    return;
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}
