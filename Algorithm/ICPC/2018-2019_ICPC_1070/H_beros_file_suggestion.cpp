#include <iostream>
#include <string>

using namespace std;

// n개의 파일명. f1, f2, ... fn
// 각각의 파일명의 길이: 1~8. 같은 파일명은 없음.
// 소문자 숫자 . 으로 이루어짐

void find_query(const string files[], int n, string s) {
    string match = "-";
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (files[i].find(s) != string::npos) {
            if (count == 0) match = files[i];
            count++;
        }
    }
    cout << count << " " << match << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // 파일명 입력
    int n;  // 파일 총개수
    cin >> n;
    string* files = new string[n];  // 파일명
    for (int i = 0; i < n; i++) cin >> files[i];

    // query 입력
    int q;
    cin >> q;
    string* keywords = new string[q];
    for (int i = 0; i < q; i++) cin >> keywords[i];

    for (int i = 0; i < q; i++) find_query(files, n, keywords[i]);

    delete[] files;
    delete[] keywords;
}