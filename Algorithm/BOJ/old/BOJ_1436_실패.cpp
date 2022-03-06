#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

// 10^y
ll ten_pow(ll y) {
    if (y < 0) return 0;
    if (y == 0)
        return 1;
    ll ret = ten_pow(y / 2);
    ret *= ret;
    if (y % 2 == 1)
        ret *= 10;
    return ret;
}

// 3자리수 = 1
// 666

// 4자리수 = 19
// (3자리수*6 / 0 + 10 + 0 / 3자리수*3)
// 0666~5666 /  6660~6669 /7666~9666

// 5자리수 = 280
// (4자리수*6 / 3자리수*6 + 100 + 3자리수*3 / 4자리수*3)
// 00666~59666 / 60666~65666, 66600~66699, 67600~69600 / 70666~99666

// 6자리수 = 3700
// (5자리수*6 / 4자리수*6 + 3자리수*6 + 1000 + 3자리수*3 + 4자리수*3 / 5자리수*3)
// 000666~599666 / 600666~659666, 660666~665666, 666000~666999, 667666~669666, 670666~699666 / 700666~999666

// 7자리수 = 45991
// 5자리수*6 + 4자리수*6 + 10000 + 4자리수*3 + 5자리*3
// 6000666~6599666, 6600666~6659666, 6660000~6669999, 6670666~6699666

// n자리수
// n-1자리수*6 / n-2자리수*6 + n-3자리수*6 + 10^(n-3) + n-3자리수*3 + n-2자리수*3 / n-1자리수*3

//2860

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    vector<ll> digits;
    digits.push_back(0);
    digits.push_back(0);
    digits.push_back(0);
    digits.push_back(1);

    ll pos = 3;  // 자릿수
    while (1) {
        if (digits.back() >= n) break;
        pos++;
        digits.push_back(
            digits[pos - 1] * 6 + digits[pos - 2] * 6 + digits[pos - 3] * 6 + ten_pow(pos - 3) + digits[pos - 1] * 3 + digits[pos - 2] * 3 + digits[pos - 3] * 3);
    }

    int ret = 0;
    while (pos > 3) {
        // pos번째 자리수가 0~5인 경우
        if (n <= 6 * digits[pos - 1]) {
            ret += ((n - 1) / digits[pos - 1]) * ten_pow(pos - 1);
            n = (n - 1) % digits[pos - 1] + 1;
        }
        // pos번째 자리수가 6인 경우
        else if (n <= digits[pos] - digits[pos - 1] * 3) {
            n -= 6 * digits[pos - 1];
            ret += 6 * ten_pow(pos - 1);

            // pos번째 자리수만 6인 경우
            if (n <= digits[pos - 2] * 6) {
                pos -= 1;
                continue;
            }
            // pos-1번쨰 자리수도 6인 경우
            else if (n <= digits[pos - 2] * 6 + digits[pos - 3] * 6) {
                n -= digits[pos - 2] * 6;
                pos -= 2;
                ret += 6 * ten_pow(pos - 2);
                continue;
            }
            // 666으로 시작하는 경우뿐만 아니라 모든 경우를 각각 처리해줘야한다. 여기서 오류가 남.
            else if (n <= digits[pos - 2] * 6 + digits[pos - 3] * 6 + ten_pow(pos - 3)) {
                n -= digits[pos - 2] * 6 + digits[pos - 3] * 6;
                ret += 66 * ten_pow(pos - 3);
                ret += n - 1;
                break;
            }
            // pos번쨰 자리수가 6이고, pos-1번째 자리수도 6이고 pos-2번쨰 자리수가 7이상인경우
            else if (n <= digits[pos - 2] * 6 + digits[pos - 3] * 9 + ten_pow(pos - 3)) {
                n -= digits[pos - 2] * 6 + digits[pos - 3] * 6 + ten_pow(pos - 3);

                pos -= 3;
                ret += 6 * ten_pow(pos - 2);

                ret += ((n - 1) / digits[pos - 3] + 1) * ten_pow(pos - 3);
                n = (n - 1) % digits[pos - 3] + 1;

                continue;
            } else {
                n -= 
            }
        }
        // pos번째 자리수가 7~9인 경우
        else {
            n -= digits[pos - 2] * 6 + digits[pos - 3] * 6 + ten_pow(pos - 3) + digits[pos - 2] * 3 + digits[pos - 3] * 3;
            n += digits[pos - 1];
            ret += ((n - 1) / digits[pos - 1]) * ten_pow(pos - 1);
            n = (n - 1) % digits[pos - 1] + 1;
        }
        pos--;
    }
    if (pos == 3) ret += 666;

    cout << ret << '\n';
}