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

void heapify(vector<int>& arr) {
    for (int i = (arr.size() - 2) / 2; i >= 0; i--) {
        int cur = i;
        while (cur * 2 + 1 < arr.size()) {
            int leftchild = cur * 2 + 1;
            int rightchild = cur * 2 + 2;
            //right child가 없는 경우
            if (rightchild >= arr.size()) {
                if (arr[cur] < arr[leftchild]) {
                    int temp = arr[leftchild];
                    arr[leftchild] = arr[cur];
                    arr[cur] = temp;
                    cur = leftchild;
                } else
                    break;
            } else {
                int maxchild;
                if (arr[leftchild] > arr[rightchild])
                    maxchild = leftchild;
                else
                    maxchild = rightchild;

                if (arr[cur] < arr[maxchild]) {
                    int temp = arr[maxchild];
                    arr[maxchild] = arr[cur];
                    arr[cur] = temp;
                    cur = maxchild;
                } else
                    break;
            }
        }
    }
}

void heapsort(vector<int>& arr) {
    int last = arr.size() - 1;
    while (last > 0) {
        int temp = arr[0];
        arr[0] = arr[last];
        arr[last] = temp;
        last--;

        int cur = 0;
        while (cur * 2 + 1 <= last) {
            int leftchild = cur * 2 + 1;
            int rightchild = cur * 2 + 2;
            //right child가 없는 경우
            if (rightchild > last) {
                if (arr[cur] < arr[leftchild]) {
                    int temp = arr[leftchild];
                    arr[leftchild] = arr[cur];
                    arr[cur] = temp;
                    cur = leftchild;
                } else
                    break;
            } else {
                int maxchild;
                if (arr[leftchild] > arr[rightchild])
                    maxchild = leftchild;
                else
                    maxchild = rightchild;

                if (arr[cur] < arr[maxchild]) {
                    int temp = arr[maxchild];
                    arr[maxchild] = arr[cur];
                    arr[cur] = temp;
                    cur = maxchild;
                } else
                    break;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto& a : arr) cin >> a;

    heapify(arr);
    heapsort(arr);

    for (auto& a : arr) cout << a << '\n';
}