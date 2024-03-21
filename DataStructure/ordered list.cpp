#include <bits/stdc++.h>
using namespace std;
const int MAXSIZE = 1e5;

class OrderList
{
private:
    int data[MAXSIZE];
    int _length;
    int _maxSize = MAXSIZE;

public:
    OrderList()
    {
        this->_length = 0;
    }
    OrderList(int arr[], int _size)
    {
        for (int i = 0; i < _size; ++i)
            ListInsert(arr[i]);
    };

    bool Menu()
    {
        cout << "1、ListEmpty()\n";
        cout << "2、ListLength()\n";
        cout << "3、DispList()\n";
        cout << "4、GetElem(index, val)\n";
        cout << "5、LocateElem(val)\n";
        cout << "6、ListInsert(index, val)\n";
        cout << "7、ListDelete(index, val)\n";
        int op, index, val;
        bool flag;
        cin >> op;
        switch (op)
        {
        case 1:
            if (ListEmpty())
                cout << "List is empty!\n";
            else
                cout << "List is not empty!\n";
            break;
        case 2:
            cout << "The List of length is " << ListLength() << "!\n";
            break;
        case 3:
            cout << "Print list:";
            DispList();
            break;
        case 4:
            cin >> index;
            flag = GetElem(index, val);
            if (flag)
                cout << "The" << index << "th value in the list is " << val << "!\n";
            else
                cout << "INDEX ERROR!\n";
            break;
        case 5:
            cin >> val;
            index = LocateElem(val);
            if (index != 0)
                cout << val << "is at number " << index << "in the list!\n";
            else
                cout << "The value not found in list!\n";
            break;
        case 6:
            cin >> val;
            flag = ListInsert(val);

            if (flag)
                cout << "Inserted successfully!\n";
            else
                cout << "Insertion failed!\n";
            break;
        case 7:
            cin >> index;
            flag = ListDelete(index, val);
            if (flag)
                cout << "Successfully deleted " << val << "!\n";
            else
                cout << "Failed to delete!\n";
            break;
        default:
            return false;
        }
        return true;
    }

    bool ListEmpty()
    {
        return this->_length == 0;
    }

    int ListLength()
    {
        return this->_length;
    }

    void DispList()
    {
        for (int i = 0; i < this->_length; ++i)
            cout << this->data[i] << " ";
        cout << "\n";
    }

    bool GetElem(int index, int &val)
    {
        if (index < 1 || index > this->_length)
            return false;
        val = this->data[index - 1];
        return true;
    }

    int LocateElem(int val)
    {
        int index = 0;
        for (int i = 0; i < this->_length; ++i)
            if (this->data[i] == val)
            {
                index = i + 1;
                break;
            }
        return index;
    }

    bool ListInsert(int val)
    {
        if (this->_length == _maxSize)
            return false;
        int index = 0;
        for (index = 0; index < this->_length; ++index)
        {
            if (this->data[index] >= val)
                break;
        }
        for (int i = this->_length; i > index; --i)
            this->data[i] = this->data[i - 1];
        this->data[index] = val;
        this->_length++;
        return true;
    }

    bool ListDelete(int index, int &val)
    {
        if (index < 1 || index > this->_length)
            return false;
        for (int i = index - 1; i < this->_length; ++i)
            this->data[i] = this->data[i + 1];
        this->_length--;
        return true;
    }
};

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    OrderList *MYLIST = new OrderList(arr, 9);
    while (MYLIST->Menu())
        ;
}