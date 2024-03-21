#include <bits/stdc++.h>

using namespace std;

struct _list
{
    int num, key;
    struct _list *next;
};

void solve(_list *pre, _list *cur, int M)
{
    // 当只剩一个节点时
    if (cur == pre)
    {
        cout << cur->num << " ";
        delete cur;
        return;
    }
    for (int i = 1; i < M; ++i)
    {
        pre = cur;
        cur = cur->next;
    }

    // 删除当前节点
    cout << cur->num << " ";
    pre->next = cur->next;
    M = cur->key;
    delete cur;
    cur = pre->next;
    
    solve(pre, cur, M);
}

int main()
{
    int n, m, key;
    cin >> n >> m;
    _list *pre = NULL, *cur = NULL, *head = NULL;

    // 创建链表
    for (int i = 1; i <= n; ++i)
    {
        cin >> key;
        if (head == NULL)
        {
            cur = new _list();
            cur->num = i;
            cur->key = key;
            head = cur;
        }
        else
        {
            pre = cur;
            cur = new _list();
            pre->next = cur;
            cur->num = i;
            cur->key = key;
        }
    }
    // 把头和尾相连
    cur->next = head;

    // 递归
    solve(cur, head, m);
    return 0;
}