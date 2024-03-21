#include <bits/stdc++.h>
using namespace std;
const int MAXSIZE = 5;
class Queue
{
private:
    int data[MAXSIZE];
    int front, rear;
    int _maxSize = MAXSIZE;

public:
    Queue()
    {
        this->front = this->rear = 0;
    }

    bool Menu()
    {
        cout << "1、QueueEmpty()\n";
        cout << "2、enQueue(int val)\n";
        cout << "3、deQueue(int &val)\n";
        cout << "4、GetFront(int &val)\n";
        int op, index, val;
        bool flag;
        cin >> op;
        switch (op)
        {
        case 1:
            if (QueueEmpty())
                cout << "Queue is empty!\n";
            else
                cout << "Queue is not empty!\n";
            break;

        case 2:
            cout << "Enter the val to add:\n";
            cin >> val;
            flag = enQueue(val);
            if (flag)
                cout << "enQueue successful!\n";
            else
                cout << "enQueue failed!\n";
            break;
        case 3:
            flag = deQueue(val);
            if (flag)
                cout << "deQueue " << val << " successful!\n";
            else
                cout << "deQueue failed!\n";
            break;
        case 4:
            flag = GetFront(val);
            if (flag)
                cout << "The front of queue is " << val << "!\n";
            else
                cout << "ERROR!\n";
            break;
        default:
            return false;
        }
        return true;
    }

    bool QueueEmpty()
    {
        return this->front == this->rear;
    }

    bool enQueue(int val)
    {
        if ((this->rear + 1) % this->_maxSize == this->front)
            return false;
        this->rear = (this->rear + 1) % this->_maxSize;
        this->data[this->rear] = val;
        return true;
    }

    bool deQueue(int &val)
    {
        if (this->front == this->rear)
            return false;
        this->front = (this->front + 1) % this->_maxSize;
        val = this->data[this->front];
        return true;
    }

    bool GetFront(int &val)
    {
        if (this->front == this->rear)
            return false;
        val = this->data[(this->front + 1) % this->_maxSize];
        return val;
    }
};

int main()
{
    Queue *MYQU = new Queue();
    while (MYQU->Menu())
        ;
    return 0;
}