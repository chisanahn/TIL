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

class heap {
    // perfect binary tree이므로 배열로 구현하는 것이 더 편하다.
    int arr[100000];
    int size;

   public:
    heap() {
        size = 0;
    }
    int pop() {
        if (size == 0) return 0;

        int del_item = arr[0];
        arr[0] = arr[size - 1];
        size--;

        int index = 0;
        while (1) {
            int left = index * 2 + 1;
            int right = index * 2 + 2;
            // child 노드가 없는경우
            if (left >= size) break;
            // left child 노드만 있는 경우
            else if (right >= size) {
                if (arr[index] > arr[left]) {
                    int temp = arr[index];
                    arr[index] = arr[left];
                    arr[left] = temp;
                }
                break;
            }
            // child 노드가 모두 있는 경우
            else if (arr[index] > min(arr[left], arr[right])) {
                if (arr[left] < arr[right]) {
                    int temp = arr[index];
                    arr[index] = arr[left];
                    arr[left] = temp;
                    index = left;
                } else {
                    int temp = arr[index];
                    arr[index] = arr[right];
                    arr[right] = temp;
                    index = right;
                }
            } else
                break;
        }
        return del_item;
    }
    void push(int x) {
        arr[size] = x;
        int index = size;
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (arr[index] < arr[parent]) {
                int temp = arr[index];
                arr[index] = arr[parent];
                arr[parent] = temp;
                index = parent;
            } else
                break;
        }
        size++;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    heap h;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 0)
            cout << h.pop() << '\n';
        else
            h.push(x);
    }
}