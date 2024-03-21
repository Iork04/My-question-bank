// https : // www.lanqiao.cn/problems/3494/learning/?page=1&first_category_id=1&tags=2023
#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
int Month[13] = {
    0,
    31,
    59,
    90,
    120,
    151,
    181,
    212,
    243,
    273,
    304,
    334,
    365};
const int daySecond = 24 * 60 * 60;
const int hourSecond = 60 * 60;

vector<int> arr;

void solve()
{
    string str;
    for (int i = 1; i <= 520; ++i)
    {
        int day, hour, second, month, minute;
        getline(cin, str);

        month = (str[5] - '0') * 10 + str[6] - '0';
        day = (str[8] - '0') * 10 + str[9] - '0';
        hour = (str[11] - '0') * 10 + str[12] - '0';
        minute = (str[14] - '0') * 10 + str[15] - '0';
        second = (str[17] - '0') * 10 + str[18] - '0';
        arr.push_back(Month[month - 1] * daySecond + day * daySecond + hour * hourSecond + minute * 60 + second);
    }
    sort(arr.begin(), arr.end());
    i64 ans = 0;
    for (int i = 0; i < arr.size(); i += 2)
    {
        ans += arr[i + 1] - arr[i];
    }
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