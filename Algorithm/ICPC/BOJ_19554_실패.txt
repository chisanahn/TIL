#include <iostream>

using namespace std;

int main() {
	int x, p, res;
	cin >> x;
	int left = 1, right = 1000000000;
	int middle;
	while (1) {
		middle = left + (right - left) / 2;
		cout << "? " << middle << endl;
		cin >> res;
		if (res == 0) {
			cout << "= " << middle << endl;
			break;
		}
		if (res == -1) {
			left = middle + 1;
		}
		if (res == 1) {
			right = middle - 1;
		}
	}
}