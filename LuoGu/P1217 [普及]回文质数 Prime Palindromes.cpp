#include <bits/stdc++.h>
using namespace std;
bool isHWS(int num)
{

    int temp = num, ans = 0;
    while (temp != 0)
    {
        ans = ans * 10 + temp % 10;
        temp /= 10;
    }
    if (ans == num)
        return true;
    else
        return false;
}
int main()
{
    int a, b;
    cin >> a >> b;
    if (a > b)
        return 0;
    if (b >= 10000000)
        b = 9999999;
    bool isPrime[b + 10];
    memset(isPrime, true, sizeof(isPrime));
    isPrime[1] = false;
    int sqrtNum = sqrt(b);
    for (int i = 2; i <= sqrtNum; i++)
    {
        if (isPrime[i])
        {
            for (int j = 2; j <= b / i; j++)
                isPrime[i * j] = false;
        }
    }
    int start = a;
    if (start <= 2)
    {
        start = 3;
    }
    else if (start % 2 == 0)
    {
        start++;
    }
    for (; start <= b; start += 2)
    {
        // cout << start << "\n";
        if (isPrime[start] && isHWS(start))
            cout << start << "\n";
    }
    return 0;
}