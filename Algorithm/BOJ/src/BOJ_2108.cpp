#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int mode(map<int, int>& M) {
    int max_count = 0;
    int count = 0;
    int ret;
    for(auto& m : M) {
        if(m.second == max_count) {
            if(count == 1) {
                ret = m.first;
            }
            count++;
        }
        else if(m.second > max_count) {
            max_count = m.second;
            count = 1;
            ret = m.first;
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; // n은 홀수라고 가정.
    cin >> n;

    // map으로 최빈값 계산.

    map<int, int> arr_m;
    vector<int> arr_v;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        arr_m[input] += 1;
        arr_v.push_back(input);
    }
    sort(arr_v.begin(), arr_v.end());

    // 산술평균
    double ret = 0;
    for (auto &v : arr_v)
        ret += (double)v;
    ret /= arr_v.size();
    if(ret>0) ret += 0.5;
    else ret -=0.5;
    cout << (int)ret << '\n';

    // 중앙값
    cout << arr_v[n/2] << '\n';

    // 최빈값 구하기.
    cout << mode(arr_m) << '\n';

    // 범위 구하기
    cout << arr_v.back() - arr_v.front() << '\n';
}