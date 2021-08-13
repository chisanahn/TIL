#include <iostream>
#include <string>

using namespace std;

int changer(int a, int b, string& s) {
	// 둘다 홀수일 경우 불가.
	if (a % 2 == 1 && b % 2 == 1) return -1;

	// 홀수개 있어야 하는 수가 문자열 가운데에 없는 경우 불가
	// ?인 경우 그 수로 바꿔준다.
	if (a % 2 == 1) {
		if (s[s.size() / 2] == '1') return -1;
		else if (s[s.size() / 2] == '?') s[s.size() / 2] = '0';
		a--;
	}
	if (b % 2 == 1) {
		if (s[s.size() / 2] == '0') return -1;
		else if (s[s.size() / 2] == '?') s[s.size() / 2] = '1';
		b--;
	}

	// 이미 있는 경우에 맞춰서 0과 1을 채워준다.
	for (int i = 0; i < s.size() / 2; i++) {
		if (s[i] != '?') {
			if (s[s.size() - i - 1] == '?')
				s[s.size() - i - 1] = s[i];
			else if (s[s.size() - i - 1] != s[i])
				return -1;
		}
		else if(s[s.size() - i - 1] != '?')
			s[i] = s[s.size() - i - 1];
		
		if (s[i] == '0') a -= 2;
		if (s[i] == '1') b -= 2;
	}

	// 부족한 개수만큼 빈자리에 채워준다.
	int i;
	for (i = 0; i < s.size() / 2; i++) {
		if (a == 0) break;
		if (s[i] == '?') {
			s[i] = '0';
			s[s.size() - i - 1] = '0';
			a -= 2;
		}
	}
	for (; i < s.size() / 2; i++) {
		if (b == 0) break;
		if (s[i] == '?') {
			s[i] = '1';
			s[s.size() - i - 1] = '1';
			b -= 2;
		}
	}

	if (a != 0 || b != 0) return -1;
	return 0;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		string s;
		cin >> a >> b;
		cin >> s;
		if (changer(a, b, s) == -1)
			cout << -1 << "\n";
		else
			cout << s << "\n";
	}
}