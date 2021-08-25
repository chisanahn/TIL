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
    int left_h;
    int right_h;
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
    void push(int n) {
        if(empty()) {
            node new_node = new node;
            new_node.item = n;
            new_node.leftchild = NULL;
            new_node.rightchild = NULL;
            new_node.parent = NULL;
            

            head = new_node;
            minp = new_node;
            maxp = new_node;
        }
        else {

        }
    }
    void pop(int n) {
        if (n == -1) {
        } else if (n == 1) {
        }
    }
    int min() {
        node* minp = head;
        while(minp->leftchild == NULL) {
            minp = minp->leftchild;
        }
        return minp->item;
    }
    int max() {
        node* maxp = head;
        while(maxp->rightchild == NULL) {
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
            cout << Q.max() << " " << Q.min() << '\n';
    }