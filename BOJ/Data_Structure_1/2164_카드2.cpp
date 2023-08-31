#include<iostream>
#include<queue>

using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N;
	queue<int> card;
	cin >> N;

	for (int i = 0; i < N; i++) {
		card.push(i + 1);
	}

	while (card.size() > 1) {
		card.pop();
		card.push(card.front());
		card.pop();
	}

	cout << card.front();

	return 0;
}