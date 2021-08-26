#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long, long>;

struct node {
    int item;
    node* parent;
    node* leftchild;
    node* rightchild;

    node(int n) {
        item = n;
        parent = NULL;
        leftchild = NULL;
        rightchild = NULL;
    }
};

class dualqueue {
    node* head;

   public:
    dualqueue() {
        head = NULL;
    }
    bool empty() {
        if (head == NULL) return true;
        return false;
    }
    int height(node* n) {
        if (n == NULL) return -1;
        int left = height(n->leftchild);
        int right = height(n->rightchild);
        return max(left, right) + 1;
    }
    bool balance(node* n) {
        int left = height(n->leftchild);
        int right = height(n->rightchild);
        if (left > right) {
            if (left - right < 2)
                return true;
            else
                return false;
        } else {
            if (right - left < 2)
                return true;
            else
                return false;
        }
    }
    void balancing() {
        if(empty()) return;
        if (balance(head)) return;

        node* z = head;
        while (1) {
            int left = height(z->leftchild);
            int right = height(z->rightchild);
            if (left > right) {
                if (balance(z->leftchild)) break;
                z = z->leftchild;
            } else {
                if (balance(z->rightchild)) break;
                z = z->rightchild;
            }
        }

        node* y;
        node* x;

        int left = height(z->leftchild);
        int right = height(z->rightchild);
        if (left > right) {
            y = z->leftchild;
            left = height(y->leftchild);
            right = height(y->rightchild);
            if(left>right) {
                x = y->leftchild;

                z->leftchild = y->rightchild;
                y->rightchild = z;
                y->parent = z->parent;
                z->parent = y;

                if(head == z) head = y;
            }
            else {
                x = y->rightchild;

                z->leftchild = x;
                y->rightchild = x->leftchild;
                x->leftchild = y;
                x->parent = z;
                y->parent = x;

                z->leftchild = x->rightchild;
                x->rightchild = z;
                x->parent = z->parent;
                z->parent = x;

                if(head == z) head = x;
            }
        }
        else {
            y = z->rightchild;
            left = height(y->leftchild);
            right = height(y->rightchild);
            if(right>left) {
                x = y->rightchild;

                z->rightchild = y->leftchild;
                y->leftchild = z;
                y->parent = z->parent;
                z->parent = y;

                if(head == z) head = y;
            }
            else {
                x = y->leftchild;

                z->rightchild = x;
                y->leftchild = x->rightchild;
                x->rightchild = y;
                x->parent = z;
                y->parent = x;

                z->rightchild = x->leftchild;
                x->leftchild = z;
                x->parent = z->parent;
                z->parent = x;

                if(head == z) head = x;
            }
        }
    }
    void push(int n) {
        node* new_node = new node(n);
        if (empty()) {
            head = new_node;
        } else {
            node* cur = head;
            while (1) {
                if (n < cur->item) {
                    if (cur->leftchild == NULL) {
                        cur->leftchild = new_node;
                        new_node->parent = cur;
                        break;
                    }
                    cur = cur->leftchild;
                } else {
                    if (cur->rightchild == NULL) {
                        cur->rightchild = new_node;
                        new_node->parent = cur;
                        break;
                    }
                    cur = cur->rightchild;
                }
            }
        }
        balancing();
    }
    void pop(int n) {
        if (empty()) return;
        if (n == -1) {
            node* delp = head;
            while (delp->leftchild != NULL) {
                delp = delp->leftchild;
            }
            if (delp->parent == NULL)
                head = delp->rightchild;
            else
                delp->parent->leftchild = delp->rightchild;
            delete delp;
        } else if (n == 1) {
            node* delp = head;
            while (delp->rightchild != NULL) {
                delp = delp->rightchild;
            }
            if (delp->parent == NULL)
                head = delp->leftchild;
            else
                delp->parent->rightchild = delp->leftchild;
            delete delp;
        }
        balancing();
    }
    int front() {
        node* minp = head;
        while (minp->leftchild != NULL) {
            minp = minp->leftchild;
        }
        return minp->item;
    }
    int back() {
        node* maxp = head;
        while (maxp->rightchild != NULL) {
            maxp = maxp->rightchild;
        }
        return maxp->item;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        dualqueue Q;
        int K;
        cin >> K;
        while (K--) {
            string cmd;
            cin >> cmd;
            if (cmd == "I") {
                int n;
                cin >> n;
                Q.push(n);
            } else if (cmd == "D") {
                int n;
                cin >> n;
                Q.pop(n);
            }
        }
        if (Q.empty())
            cout << "EMPTY\n";
        else
            cout << Q.back() << " " << Q.front() << '\n';
    }
}