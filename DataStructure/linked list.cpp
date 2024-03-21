#include <bits/stdc++.h>
using namespace std;

class LinkList
{
private:
    struct LNode
    {
        int data;
        LNode *next;
    };
    LNode *_dummyHead;
    int _length;

public:
    LinkList()
    {
        this->_dummyHead = new LNode();
        this->_dummyHead->next = nullptr;
    }
    LinkList(int arr[], int _size)
    {
        this->_dummyHead = new LNode();
        this->_dummyHead->next = nullptr;
        LNode *pre = _dummyHead;
        for (int i = 0; i < _size; ++i)
        {
            LNode *cur = new LNode();
            cur->data = arr[i];
            cur->next = nullptr;
            pre->next = cur;
            pre = cur;
            this->_length++;
        }
    }
    ~LinkList()
    {
        LNode *cur = this->_dummyHead->next;
        LNode *next = nullptr;
        while (cur != nullptr)
        {
            next = cur->next;
            delete cur;
            cur = next;
        }
        delete this->_dummyHead;
    }

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
            cin >> index >> val;
            if (index == 0)
                flag = ListInsert(val);
            else
                flag = ListInsert(index, val);

            if (flag)
                cout
                    << "Inserted successfully!\n";
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
        return this->_dummyHead->next == nullptr;
    }

    int ListLength()
    {
        return this->_length;
    }

    void DispList()
    {
        LNode *cur = this->_dummyHead->next;
        while (cur != nullptr)
        {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << "\n";
    }

    bool GetElem(int index, int &val)
    {
        if (index < 1 || index > this->_length)
            return false;
        LNode *cur = this->_dummyHead;
        while (index--)
            cur = cur->next;
        val = cur->data;
        return true;
    }

    int LocateElem(int val)
    {
        int index = 0;
        LNode *cur = this->_dummyHead->next;
        while (cur != nullptr)
        {
            index++;
            if (cur->data == val)
                return index;
            cur = cur->next;
        }
        return 0;
    }

    bool ListInsert(int index, int val)
    {
        if (index < 1 || index > this->_length)
            return false;
        index--;
        LNode *pre = this->_dummyHead;

        while (index--)
            pre = pre->next;
        LNode *cur = new LNode();
        cur->data = val;
        cur->next = pre->next;
        pre->next = cur;
        this->_length++;
        return true;
    }

    bool ListInsert(int val)
    {
        LNode *pre = this->_dummyHead;
        while (pre->next != nullptr)
            pre = pre->next;
        LNode *cur = new LNode();
        cur->data = val;
        cur->next = nullptr;
        pre->next = cur;
        this->_length++;
        return true;
    }

    bool ListDelete(int index, int &val)
    {
        if (index < 1 || index > this->_length)
            return false;
        index--;
        LNode *pre = this->_dummyHead;

        while (index--)
            pre = pre->next;

        val = pre->next->data;
        LNode *tmp = pre->next;
        pre->next = tmp->next;
        delete tmp;
        this->_length--;
        return true;
    }
};

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    LinkList *MYLIST = new LinkList(arr, 9);
    while (MYLIST->Menu())
        ;
    return 0;
}