#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

class SegTree {
    int start;  // 맨 아래층 시작점이자 맨 아래층 길이, S[start+i]= A[i]
    vector<ll> S;
    int a_size;  // A.size()
   public:
    SegTree(vector<ll>& A) : S(vector<ll>(A.size() * 4, 0)), a_size(A.size()) {
        start = 1;
        while (start < A.size()) start *= 2;
        // 맨 아래층 원소들 업데이트
        for (int i = 0; i < A.size(); i++) {
            S[i + start] = A[i];
        }
        // 다른 요소들 업데이트
        int index = start;
        while (index > 1) {
            index--;
            S[index] = S[index * 2] + S[index * 2 + 1];
        }
    }
    // A[n]을 value값으로 업데이트

    void update(int n, ll value) {
        // 맨 아래층 업데이트
        int index = start + n;
        S[index] = value;
        // 관련 원소들 업데이트
        while (index > 1) {
            index /= 2;
            S[index] = S[index * 2] + S[index * 2 + 1];
        }
    }
    // A[left] ~ A[right]의 구간 합
    ll ret(int left, int right, int S_index, int L, int R) {
        // 범위에 맞는 경우
        if (left == L && right == R)
            return S[S_index];
        // 범위가 더 작은 경우 재귀처리
        else {
            int mid = (L + R) / 2;
            if (mid >= right)
                return ret(left, right, S_index * 2, L, mid);
            else if (mid + 1 <= left)
                return ret(left, right, S_index * 2 + 1, mid + 1, R);
            else
                return ret(left, mid, S_index * 2, L, mid) + ret(mid + 1, right, S_index * 2 + 1, mid + 1, R);
        }
    }
    // 인터페이스
    ll ret(int left, int right) {
        // 예외 처리
        if(left < 0 || right >= a_size) return 0;
        return ret(left, right, 1, 0, start - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> A(n);
    for (auto& a : A) cin >> a;
    SegTree ST(A);
    for (int i = 0; i < k + m; i++) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int b;
            ll c;
            cin >> b >> c;
            b--;
            ST.update(b, c);
        } else {
            int b, c;
            cin >> b >> c;
            b--;
            c--;
            cout << ST.ret(b, c) << '\n';
        }
    }
}