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
// PeiShu's theorem:If d=gcd(a,b).
// Than ax+by is an integer multiple of d.
// ax+by=d has an integer solution.
// ax+by=gcd(a,b)=gcd(b,a%b)=bx_*(a%b)y_
tuple<int, int, int> extended_gcd(int a, int b)
{
    if (b == 0)
        return {a, 1, 0};
    int gcd, _x, _y;
    tie(gcd, _x, _y) = extended_gcd(b, a % b);
    int x = _y, y = _x - (a / b) * _y;
    return {gcd, x, y};
}
void solve()
{
    int a = 48, b = 18;
    cout << "GCD of " << a << " and " << b << " using Euclidean algorithm: " << gcd(a, b) << endl;

    int d, x, y;
    tie(d, x, y) = extended_gcd(a, b);
    cout << "GCD of " << a << " and " << b << " using Extended Euclidean algorithm: " << d << endl;
    cout << "Coefficients x and y: " << x << ", " << y << endl;
}
int main()
{
    solve();
    return 0;
}