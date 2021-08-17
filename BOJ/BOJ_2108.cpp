#include <iostream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    map<int, int> arr;
    int min=4000, max=-4000, sum=0;
    for(int i=0; i<n; i++) {
        int num;
        cin >> num;
        if(min > num) min = num;
        if(max < num) max = num;
        sum += num;
        arr[num] += 1;
    }
    int mean = sum / n;

    int second;
    arr.
    for(auto& a: arr) {

    }
}