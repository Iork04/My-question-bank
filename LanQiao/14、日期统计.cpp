#include <bits/stdc++.h>
using namespace std;
const int numbers[100] = {5, 6, 8, 6, 9, 1, 6, 1, 2, 4, 9, 1, 9, 8, 2, 3, 6, 4, 7, 7, 5, 9, 5, 0, 3, 8, 7, 5, 8, 1, 5,
                          8, 6, 1, 8, 3, 0, 3, 7, 9, 2, 7, 0, 5, 8, 8, 5, 7, 0, 9, 9, 1, 9, 4, 4, 6, 8, 6, 3, 3, 8, 5,
                          1, 6, 3, 4, 6, 7, 0, 7, 8, 2, 7, 6, 8, 9, 5, 6, 5, 6, 1, 4, 0, 1, 0, 0, 9, 4, 8, 0, 9, 1, 2,
                          8, 5, 0, 2, 5, 3, 3};
const int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void solve()
{
    int ans = 0;
    for (int i = 1; i <= 12; ++i)
    {
        for (int j = 1; j <= days[i]; ++j)
        {
            string now = "2023";
            if (i < 10)
                now += "0";
            now += to_string(i);
            if (j < 10)
                now += "0";
            now += to_string(j);
            int index = 0;
            for (int k = 0; k < 100 && index < 8; ++k)
            {
                if (now[index] - '0' == numbers[k])
                    index++;
            }
            if (index >= 8)
                ans++;
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