#include <iostream>
#include <string>

using namespace std;

struct node
{
    int item;
    node *prev;
    node *next;
};

class Deque
{
    int _size;
    node *_front;
    node *_back;

public:
    Deque()
    {
        _size = 0;
        _front = NULL;
        _back = NULL;
    }
    void push_front(int x)
    {
        node *new_node = new node;
        new_node->item = x;
        new_node->prev = NULL;
        new_node->next = _front;
        if (_size == 0)
            _back = new_node;
        else
            _front->prev = new_node;
        _front = new_node;
        _size++;
    }
    void push_back(int x)
    {
        node *new_node = new node;
        new_node->item = x;
        new_node->next = NULL;
        new_node->prev = _back;
        if (_size == 0)
            _front = new_node;
        else
            _back->next = new_node;
        _back = new_node;
        _size++;
    }
    int pop_front()
    {
        if (_size == 0)
            return -1;
        int del_item = _front->item;
        node *del_node = _front;

        _front = del_node->next;
        if (_size == 1)
            _back = NULL;
        else
            _front->prev = NULL;

        _size--;
        delete del_node;
        return del_item;
    }
    int pop_back()
    {
        if (_size == 0)
            return -1;
        int del_item = _back->item;
        node *del_node = _back;

        _back = del_node->prev;
        if (_size == 1)
            _front = NULL;
        else
            _back->next = NULL;
        _size--;
        delete del_node;
        return del_item;
    }
    int size()
    {
        return _size;
    }
    bool empty()
    {
        if (_size == 0)
            return true;
        else
            return false;
    }
    int front()
    {
        if (_size == 0)
            return -1;
        return _front->item;
    }
    int back()
    {
        if (_size == 0)
            return -1;
        return _back->item;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    Deque d;
    while (N--)
    {
        string cmd;
        cin >> cmd;
        if (cmd == "push_front")
        {
            int x;
            cin >> x;
            d.push_front(x);
        }
        else if (cmd == "push_back")
        {
            int x;
            cin >> x;
            d.push_back(x);
        }
        else if (cmd == "pop_front")
        {
            cout << d.pop_front() << '\n';
        }
        else if (cmd == "pop_back")
        {
            cout << d.pop_back() << '\n';
        }
        else if (cmd == "size")
        {
            cout << d.size() << '\n';
        }
        else if (cmd == "empty")
        {
            cout << d.empty() << '\n';
        }
        else if (cmd == "front")
        {
            cout << d.front() << '\n';
        }
        else if (cmd == "back")
        {
            cout << d.back() << '\n';
        }
    }
}