// https://www.luogu.com.cn/problem/P1449
// 模拟、队列
#include <bits/stdc++.h>
using namespace std;
stack<int> st;

void func(char op)
{
    int a, b, c;
    b = st.top();
    st.pop();
    a = st.top();
    st.pop();
    if (op == '+')
    {
        c = a + b;
        st.push(c);
    }
    else if (op == '-')
    {
        c = a - b;
        st.push(c);
    }
    else if (op == '*')
    {
        c = a * b;
        st.push(c);
    }
    else
    {
        c = a / b;
        st.push(c);
    }
    // cout << st.top() << " ";
}
void solve()
{
    string str;
    cin >> str;
    int val = 0;
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == '.')
        {
            st.push(val);
            // cout << val << " ";
            val = 0;
        }
        else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
            func(str[i]);
        else
            val = val * 10 + str[i] - '0';
    }
    cout << st.top();
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