#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int fibo_cal(vector<int> &fibo, int n)
{
    if (fibo[n] != -1)
        return fibo[n];
    else {
        fibo[n] = fibo_cal(fibo, n - 1) + fibo_cal(fibo, n - 2);
        return fibo[n];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> fibo(n + 1, -1);
    fibo[0] = 0;
    fibo[1] = 1;
    cout << fibo_cal(fibo, n) << '\n';
}