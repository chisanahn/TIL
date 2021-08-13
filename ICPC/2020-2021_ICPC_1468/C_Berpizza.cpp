#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct customer {
	int index;
	int money;
};

struct money_compare {
	bool operator()(customer& a, customer& b) {
		if (a.money != b.money)
			return a.money < b.money;
		return a.index > b.index;
	}
};

int main() {
	// 먼저 온 순서대로 저장
	queue<customer> time_q;
	// VIP 고객 순서대로 저장
	priority_queue<customer, vector<customer>, money_compare> money_q;
	// 주문을 받았는지 여부 저장.
	vector<int> ordered;
	// 결과 저장
	vector<int> rets;

	int sort;  // 1, 2, 3
	int money;

	int T;
	cin >> T;
	while (T--) {
		cin >> sort;
		if (sort == 1) {
			cin >> money;
			ordered.push_back(0);
			customer new_customer = { ordered.size(), money };
			time_q.push(new_customer);
			money_q.push(new_customer);
		}
		else if (sort == 2) {
			customer ret = time_q.front();
			time_q.pop();
			while (ordered[ret.index - 1] != 0) {  // 3번 웨이터가 이미 주문을 받은 손님 예외 처리
				ret = time_q.front();
				time_q.pop();
			}
			ordered[ret.index - 1] = 1;
			rets.push_back(ret.index);
		}
		else if (sort == 3) {
			customer ret = money_q.top();
			money_q.pop();
			while (ordered[ret.index - 1] != 0) {  // 2번 웨이터가 이미 주문을 받은 손님 예외 처리
				ret = money_q.top();
				money_q.pop();
			}
			ordered[ret.index - 1] = 1;
			rets.push_back(ret.index);
		}
	}
	for (int i = 0; i < rets.size(); i++) {
		cout << rets[i] << " ";
	}
	cout << "\n";
}