#include <algorithm>
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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    // 수열
    vector<int> arr(n);
    for (auto& a : arr) cin >> a;

    // 부분 수열의 최대 길이 저장
    vector<int> len(n, 1);
    // 부분 수열 경로 저장 - 해당 인덱스의 전 숫자의 인덱스를 저장
    vector<int> prev(n, -1);

    int max_index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && len[i] < len[j] + 1) {
                len[i] = len[j] + 1;
                prev[i] = j;
            }
        }
        if(len[max_index] < len[i]) max_index = i;
    }

    // 최대 부분 수열의 길이 출력
    cout << len[max_index] << '\n';
    // 최대 길이의 부분 수열 출력
    vector<int> path;
    int index = max_index;
    for(int i=0; i<len[max_index]; i++) {
        path.push_back(arr[index]);
        index = prev[index];
    }

    for(int i=path.size()-1; i>=0; i--) {
        cout << path[i] << " ";
    }
    cout << '\n';
}