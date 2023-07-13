#include<iostream>
#include<string>
#include<deque>

using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N, temp;
	string str;
	deque<int> dq;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> str;
		if (str == "push_front") {
			cin >> temp;
			dq.push_front(temp);
		}
		else if (str == "push_back") {
			cin >> temp;
			dq.push_back(temp);
		}
		else if (str == "pop_front") {
			if (!dq.empty()) {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
			else
				cout << "-1\n";
		}
		else if (str == "pop_back") {
			if (!dq.empty()) {
				cout << dq.back() << "\n";
				dq.pop_back();
			}
			else
				cout << "-1\n";
		}
		else if (str == "size") {
			cout << dq.size() << "\n";
		}
		else if (str == "empty") {
			if (!dq.empty())
				cout << "0\n";
			else
				cout << "1\n";
		}
		else if (str == "front") {
			if (!dq.empty()) 
				cout << dq.front() << "\n";
			else
				cout << "-1\n";
		}
		else if (str == "back") {
			if (!dq.empty()) 
				cout << dq.back() << "\n";
			else
				cout << "-1\n";
		}
	}

	return 0;
}