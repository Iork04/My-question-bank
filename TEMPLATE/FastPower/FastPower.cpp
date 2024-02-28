#include <iostream>
using namespace std;
typedef long long i64;

i64 fastPower(i64 x, i64 y, i64 mod)
{
    i64 res = 1;
    x %= mod, y %= mod;
    while (y)
    {
        if (y & 1)
            res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}

void solve()
{
    cout << "2的123456次方%1e9=" << fastPower(2, 123456, 1e9) << endl;
}

int main()
{
    system("chcp 65001");
    solve();
    return 0;
}