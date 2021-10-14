#include <iostream>

using namespace std;

void changer(int n, char table[]) {
	// 별표 위치 체크
	int index[2][2];
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (table[n * i + j] == '*') {
				index[count][0] = i;
				index[count][1] = j;
				count++;
			}
		}
	}
	// 같은 행에 존재하는 경우
	if (index[0][0] == index[1][0]) {
		int row;
		if (index[0][0] < n - 1) row = index[0][0] + 1;
		else row = index[0][0] - 1;
		table[n * row + index[0][1]] = '*';
		table[n * row + index[1][1]] = '*';
	}
	// 같은 열에 존재하는 경우
	else if (index[0][1] == index[1][1]) {
		int col;
		if (index[0][1] < n - 1) col = index[0][1] + 1;
		else col = index[0][1] - 1;
		table[n * index[0][0] + col] = '*';
		table[n * index[1][0] + col] = '*';
	}
	// 대각선으로 존재하는 경우
	else {
		table[n * index[0][0] + index[1][1]] = '*';
		table[n * index[1][0] + index[0][1]] = '*';
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		char table[400*400];
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> table[n*i+j];
		changer(n, table);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << table[n * i + j];
			cout << "\n";
		}
	}
}