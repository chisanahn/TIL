#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 3 containers: 종이, 플라스틱, 일반쓰레기

int main() {
	int T;
	cin >> T;
	while (T--) {
		int c1, c2, c3; // 종이, 플라스틱, 일반 컨테이너 저장용량
		int a1, a2, a3, a4, a5; // 종이, 플라스틱, 일반, 종이or일반, 플라스틱or일반
		int ret = 0;
		cin >> c1 >> c2 >> c3;
		cin >> a1 >> a2 >> a3 >> a4 >> a5;
		
		// a1, a2, a3 확인
		if (a1 > c1 || a2 > c2 || a3 > c3) cout << "NO\n";
		else {
			// a4 처리
			a1 += a4;
			if (a1 > c1) a3 += (a1 - c1);
			// a5 처리
			a2 += a5;
			if (a2 > c2) a3 += (a2 - c2);

			// 판별
			if (a3 > c3) cout << "NO\n";
			else cout << "YES\n";
		}
	}
}