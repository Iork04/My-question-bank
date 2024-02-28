#include <iostream>
#include <string>
using namespace std;

int *getNext(string str)
{
    int k = 0;
    int size = str.size();
    int *next = new int[size];
    next[0] = -1;
    for (int i = 1; i < size; ++i)
    {
        next[i] = k;
        while ((k ^ -1) && str[i] != str[k])
            k = next[k];
        ++k;
    }
    for (int i = 0; i < size; ++i)
        cout << next[i] << " ";
    cout << "\n";
    return next;
}

int getIndex(string a, string b, int *next)
{
    int i, j;
    for (i = 0, j = 0; i < a.size(); ++i, ++j)
    {
        while ((j ^ -1) && b[j] != a[i])
            j = next[j];
        if (j == b.size() - 1)
            return i - j;
    }
    return -1;
}

void solve()
{
    string a, b;
    a = "aaaaaaaaaaaabbbbbb";
    b = "aab";

    int *next = getNext(a);
    cout << getIndex(a, b, next) << "\n";
}

int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int _ = 1;
    while (_--)
        solve();
}