#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int an[N];
char a[N];
char b[N];
char c[N];
int n, lena, lenb, lenc;
void cheng1()
{
    for (int i = 1; i <= 500; i++)
    {
        for (int j = 1; j <= 500; j++)
        {
            c[i + j - 1] += a[i] * b[j];
            c[i + j] += c[i + j - 1] / 10;
            c[i + j - 1] %= 10;
        }
    }
    for (int i = 1; i <= 500; i++)
    {
        a[i] = c[i];
        c[i] = 0;
    }
}
void cheng2()
{
    for (int i = 1; i <= 500; i++)
    {
        for (int j = 1; j <= 500; j++)
        {
            c[i + j - 1] += b[i] * b[j];
            c[i + j] += c[i + j - 1] / 10;
            c[i + j - 1] %= 10;
        }
    }
    for (int i = 1; i <= 500; i++)
    {
        b[i] = c[i];
        c[i] = 0;
    }
}
int main()
{
    a[1] = 1;
    b[1] = 2;
    cin >> n;
    cout << (int)(log10(2) * n + 1) << "\n";
    while (n)
    {
        if (n % 2 == 1)
            cheng1();
        cheng2();
        n >>= 1;
    }
    a[1] -= 1;
    int index = 500;
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 50; j++)
            printf("%d", a[index--]);
        cout << "\n";
    }
    return 0;
}