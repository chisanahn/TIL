#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, l;
    cin >> n >> m >> l;

    vector<int> stations(n);
    for (auto& s : stations) cin >> s;
    stations.push_back(0);
    stations.push_back(l);
    sort(stations.begin(), stations.end());

    vector<int> lens(n + 1);
    for (int i = 0; i < stations.size() - 1; i++) {
        lens[i] = stations[i + 1] - stations[i];
    }

    int min = 1;
    int max = l;
    int mid;
    while (min < max) {
        mid = (min + max) / 2;
        int sum = 0;
        for (auto& len : lens) {
            sum += (len - 1) / mid;
        }

        if (sum > m)
            min = mid + 1;
        else
            max = mid;
    }
    cout << min << '\n';
}