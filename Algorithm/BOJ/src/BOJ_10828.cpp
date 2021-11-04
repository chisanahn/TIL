#include <iostream>
#include <string>

using namespace std;

struct node {
    int item;
    node* pre;
    node(int x) {
        item = x;
        pre = NULL;
    }
};

class Stack {
    node* head;
    int _size;

   public:
    Stack() {
        head = NULL;
        _size = 0;
    }
    bool empty() {
        return !_size;
    }
    void push(int x) {
        node* new_node = new node(x);
        if (empty()) {
            head = new_node;
        } else {
            new_node->pre = head;
            head = new_node;
        }
        _size++;
    }
    int pop() {
        if (empty()) return -1;
        node* del = head;
        int ret = del->item;
        head = head->pre;
        free(del);
        _size--;
        return ret;
    }
    int top() {
        if (empty()) return -1;
        return head->item;
    }
    int size() {
        return _size;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    Stack s;
    while (n--) {
        string input;
        cin >> input;
        if (input == "push") {
            int x;
            cin >> x;
            s.push(x);
        } else if (input == "pop") {
            cout << s.pop() << '\n';
        } else if (input == "size") {
            cout << s.size() << '\n';
        } else if (input == "empty") {
            cout << s.empty() << '\n';
        } else if (input == "top") {
            cout << s.top() << '\n';
        }
    }
}