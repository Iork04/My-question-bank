#include <bits/stdc++.h>
using namespace std;

// int gcd(int a, int b)
// {
//     return b == 0 ? a : gcd(b, a % b);
// }
int gcd(int a, int b)
{
    while (b)
    {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}
int lcm(int a, int b)
{
    return abs(a * b) / gcd(a, b);
}

void solve()
{
    int a = 48, b = 18;
    cout << "GCD of " << a << " and " << b << " using Euclidean algorithm: " << gcd(a, b) << endl;
}
int main()
{
    solve();
    return 0;
}