#include <iostream>
#include <string>

using namespace std;

struct coordinates {
	int x;
	int y;
};

// 좀 더 간단하게 생각하면 RL의 개수와 UD의 개수가 각각 동일하면 0으로 돌아간다.
// 주의! 이미 장애물이 한번 놓여지면 그 뒤로도 그 칸에서는 멈춰야한다.

// 틀린 이유:
// 1. 장애물이 0,0에 놓이면 안된다는 문제 요구사항을 깜빡함.
// 2. 경로를 따라가다가 중간에 장애물을 놓는 방식으로 구현하면 장애물을 놓기 전에 장애물과 겹치는 구간은 고려하지 못한다.

coordinates robot(const string& commands) {
	coordinates pos;
	coordinates obstacle;
	for (int i = 0; i < commands.size(); i++) {
		pos.x = 0; pos.y = 0;
		for (int j = 0; j < commands.size(); j++) {

			if (j < i) {
				if (commands[j] == 'L') pos.x--;
				if (commands[j] == 'R') pos.x++;
				if (commands[j] == 'U') pos.y++;
				if (commands[j] == 'D') pos.y--;
			}
			else if (j == i) {  // 로봇의 경로 중 한 곳에 장애물 배치
				obstacle.x = pos.x;
				obstacle.y = pos.y;
				if (commands[j] == 'L') obstacle.x--;
				if (commands[j] == 'R') obstacle.x++;
				if (commands[j] == 'U') obstacle.y++;
				if (commands[j] == 'D') obstacle.y--;
				if (obstacle.x == 0 && obstacle.y == 0) break; // 0,0에 장애물이 놓이는 경우 예외처리
			}
			else if (j > i) {   // 가기 전에 장애물이 있는지 확인
				if (commands[j] == 'L') {
					pos.x--;
					if (obstacle.x == pos.x && obstacle.y == pos.y) pos.x++;
				}
				if (commands[j] == 'R') {
					pos.x++;
					if (obstacle.x == pos.x && obstacle.y == pos.y) pos.x--;
				}
				if (commands[j] == 'U') {
					pos.y++;
					if (obstacle.x == pos.x && obstacle.y == pos.y) pos.y--;
				}
				if (commands[j] == 'D') {
					pos.y--;
					if (obstacle.x == pos.x && obstacle.y == pos.y) pos.y++;
				}
			}
		}
		if (pos.x == 0 && pos.y == 0) return obstacle;
	}
	// 올바른 장애물이 없는 경우
	return coordinates{ 0,0 };
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		string commands;
		cin >> commands;
		coordinates result = robot(commands);
		cout << result.x << " " << result.y << "\n";
	}
}

