#include <iostream>

using namespace std;

int fibo(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibo(n - 2) + fibo(n - 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();

    int n;
    cin >> n;
    cout << fibo(n) << '\n';
}