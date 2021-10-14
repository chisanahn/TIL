#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> videos(n);
    for (auto& v : videos) cin >> v;

    int ret = 0;
    for (auto& v : videos) ret += v;

    if (ret % k != 0) {
        cout << "No\n";
        return 0;
    }

    ret /= k;
    int sum = 0, count = 0;
    vector<int> ans;
    int length = 0;
    for (int i = 0; i < videos.size(); i++) {
        sum += videos[i];
        length++;
        if (sum == ret) {
            sum = 0;
            count++;
            ans.push_back(length);
            length = 0;
        }
        if (sum > ret) {
            break;
        }
    }

    if (count == k) {
        cout << "Yes\n";
        for (auto& a : ans) cout << a << " ";
        cout << '\n';
    }
    else {
        cout << "No\n";
    }
}