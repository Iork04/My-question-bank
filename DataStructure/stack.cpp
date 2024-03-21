#include <bits/stdc++.h>
using namespace std;
const int MAXSIZE = 1e5 + 10;

class Stack
{
private:
    int data[MAXSIZE];
    int top;
    int _maxSize = MAXSIZE;

public:
    Stack()
    {
        this->top = -1;
    }

    bool Menu()
    {
        cout << "1、StackEmpty()\n";
        cout << "2、Push(int val)\n";
        cout << "3、Pop(int &val)\n";
        cout << "4、GetTop(int &val)\n";
        int op, index, val;
        bool flag;
        cin >> op;
        switch (op)
        {
        case 1:
            if (StackEmpty())
                cout << "Stack is empty!\n";
            else
                cout << "Stack is not empty!\n";
            break;

        case 2:
            cout << "Enter the val to add:\n";
            cin >> val;
            flag = Push(val);
            if (flag)
                cout << "Push successful!\n";
            else
                cout << "Push failed!\n";
            break;
        case 3:
            flag = Pop(val);
            if (flag)
                cout << "Pop " << val << " successful!\n";
            else
                cout << "Pop failed!\n";
            break;
        case 4:
            flag = GetTop(val);
            if (flag)
                cout << "The top value is " << val << "!\n";
            else
                cout << "ERROR!\n";
            break;

        default:
            return false;
        }
        return true;
    }

    bool
    StackEmpty()
    {
        return this->top == -1;
    }

    bool Push(int val)
    {
        if (this->top == _maxSize - 1)
            return false;
        this->data[++this->top] = val;
        return true;
    }

    bool Pop(int &val)
    {
        if (StackEmpty())
            return false;
        val = this->data[this->top--];
        return true;
    }

    bool GetTop(int &val)
    {
        if (StackEmpty())
            return false;
        val = this->data[this->top];
        return true;
    }
};

int main()
{
    Stack *MYST = new Stack();
    while (MYST->Menu())
        ;
    return 0;
}