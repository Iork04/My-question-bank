// https://www.luogu.com.cn/problem/P3378
// 堆
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
typedef long long i64;
i64 heap[N];
int _size = 0;

void push_up(int &i, int val)
{
    while (i > 1 && val < heap[i / 2])
    {
        heap[i] = heap[i / 2];
        i /= 2;
    }
}

void push_down(int &i, int val)
{
    int ch = i * 2;
    while (ch <= _size)
    {
        if (ch < _size && heap[ch] > heap[ch + 1])
            ++ch;
        if (val <= heap[ch])
            break;
        heap[i] = heap[ch];
        i = ch;
        ch <<= 1;
    }
}

void delete_min()
{
    int i = 1, val = heap[_size--];
    push_down(i, val);
    heap[i] = val;
}

void insert(int val)
{
    int i = ++_size;
    push_up(i, val);
    heap[i] = val;
}

void solve1()
{
    int n, op, val;
    cin >> n;
    while (n--)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> val;
            insert(val);
        }
        else if (op == 2)
        {
            cout <<heap[1] << "\n";
        }
        else
        {
            delete_min();
        }
    }
}

// STL解决方案
void solve2()
{
    int n, op, val;
    cin >> n;
    priority_queue<i64, vector<i64>, greater<i64>> H;
    while (n--)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> val;
            H.push(val);
        }
        else if (op == 2)
        {
            cout << H.top() << "\n";
        }
        else
        {
            H.pop();
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    // freopen("./in.in", "r", stdin);
    int _ = 1;
    // cin >> _;
    while (_--)
        solve1();
    return 0;
}