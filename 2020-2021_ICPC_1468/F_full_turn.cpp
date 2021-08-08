#include <iostream>
#include <vector>

struct sight {
	int x;
	int y;
};

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<sight> people;
		for (int i = 0; i < n; i++) {
			int x, y, u, v;
			cin >> x >> y >> u >> v;

			int v1 = x - u, v2 = y - v;
			// 벡터 크기 통일
			int abs_v1 = abs(v1), abs_v2 = abs(v2);
			if (v1 == 0) v2 /= abs_v2;
			else if (v2 == 0) v1 /= abs(v1);
			else if (abs_v1 > abs_v2 && v1 % v2 == 0) {
				v1 /= abs_v2;
				v2 /= abs_v2;
			}
			else if (abs_v1 < abs_v2 && v2 % v1 == 0) {
				v1 /= abs_v1;
				v2 /= abs_v1;
			}
			else if (abs_v1 == abs_v2) {
				v1 /= abs_v1;
				v2 /= abs_v2;
			}

			people.push_back({ v1, v2 });
		}
		int count = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (people[i].x == -people[j].x && people[i].y == -people[j].y)
					count++;
			}
		}
		cout << count << "\n";
	}
}