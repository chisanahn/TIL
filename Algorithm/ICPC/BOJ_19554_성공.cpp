#include <iostream>

using namespace std;

int main() {
	int N, p, res;
	cin >> N;
	int left = 1, right = N;
	while (1) {
		p = left + (right - left) / 2;
		cout << "? " << p << endl;
		cin >> res;
		if (res == 0) {
			cout << "= " << p << endl;
			break;
		}
		else if (res == -1) {
			left = p + 1;
		}
		else if (res == 1) {
			right = p - 1;
		}
	}
}