// https://www.lanqiao.cn/problems/3495/learning/?page=1&first_category_id=1&tags=2023
#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void solve()
{
    int ans = 1;
    for (int i = 2000; i < 2000000; ++i)
    {
        if ((i % 400 == 0) || (i % 4 == 0 && i % 100 != 0))
            days[2] = 29;
        else
            days[2] = 28;
        for (int j = 1; j <= 12; ++j)
        {
            if (i % j == 0)
                for (int k = 1; k <= days[j]; ++k)
                {
                    if (i % k == 0)
                        ans++;
                }
        }
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}