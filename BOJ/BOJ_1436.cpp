#include <iostream>
#include <vector>

using namespace std;

// 10^y
int ten_pow(int y)
{
    if (y == 0)
        return 1;
    int ret = ten_pow(y / 2);
    ret *= ret;
    if (y % 2 == 1)
        ret *= 10;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    // 3자리수
    // 1개: 666

    // 4자리수
    // (3자리수*9 + 9)개:  1666 ~ 5666 /  6660 ~ 6669 /7666 ~ 9666

    // 5자리수
    // 3자리 + 4자리수: 10666 ~ 15666 / 16660 ~ 16669 / 17666 ~ 19666
    // ...
    // 6+99+3(3자리수 + 4자리수 + 90): 60666 ~ 65666 /66600 ~ 66699 / 67600 ~ 69600
    // ...
    // 3자리 + 4자리수: 90666 ~ 99666

    // 6자리수
    // (3+4+5)자리수 : 100666 ~ 199666
    // ...
    // (3+4+5)자리수+900 : 666000 ~ 666999

    // arr[3] = 1
    // arr[4] = arr[3]*9 + 9
    // arr[5] = (arr[3]+arr[4])*9 + 90
    // arr[6] = (arr[3]+arr[4]+arr[5])*9 + 900
    // arr[n] = (arr[3]+ ... +arr[n-1])*9 + 9*10^(n-4);

    vector<int> arr;
    arr.push_back(1);
    int pos = 0;   // 자릿수-3;
    int check = 0; // 몇번째자리수의 범위에 들어가는지 체크
    while (1)
    {
        check += arr.back();
        if (check >= n)
            break;
        int add = 0;
        for (auto &a : arr)
            add += a;
        arr.push_back(add * 9 + 9*ten_pow(pos));
        pos++;
    }

    // 해당 자릿수에서 몇번쨰 숫자인지.
    
}