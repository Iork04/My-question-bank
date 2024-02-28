#include <queue>
#include <iostream>
using namespace std;

// 自定义比较函数
struct cmpMin
{
    bool operator()(const int &a, const int &b) const
    {
        return a > b;
    }
};

struct cmpMax
{
    bool operator()(const int &a, const int &b) const
    {
        return a < b;
    }
};

void solve()
{
    // Default is big top heap.

    // Use 'greater<int>' comparison function for small heap.
    priority_queue<int, vector<int>, cmpMin> minHeap;
    minHeap.push(3);
    minHeap.push(1);
    minHeap.push(4);
    minHeap.push(1);
    while (!minHeap.empty())
    {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << "\n";

    priority_queue<int, vector<int>, cmpMax> maxHeap;
    maxHeap.push(3);
    maxHeap.push(1);
    maxHeap.push(4);
    maxHeap.push(1);
    while (!maxHeap.empty())
    {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
}

int main()
{
    int _ = 1;
    // freopen(".../in.in", "r", stdin);
    while (_--)
        solve();
}