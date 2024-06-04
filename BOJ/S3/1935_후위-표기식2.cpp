// cpp 소수점 표기법
// vector 자주 쓰기

#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main() {

	int N;
	int alpha[26];
	double t1, t2;
	string postfix;
	stack<double> s;

	cin >> N;
	cin >> postfix;
	for (int i = 0; i < N; i++) {
		cin >> alpha[i];
	}

	for (int i = 0; i < postfix.length(); i++) {
		if ('A' <= postfix[i] && postfix[i] <= 'Z') {
			s.push(alpha[postfix[i] - 'A']);
		}
		else {
			t2 = s.top();
			s.pop();

			switch (postfix[i]) {
			case '+':
				t1 = s.top();
				s.pop();
				t1 = t1 + t2;
				break;
			case '-':
				t1 = s.top();
				s.pop();
				t1 = t1 - t2;
				break;
			case '*':
				t1 = s.top();
				s.pop();
				t1 = t1 * t2;
				break;
			case '/':
				t1 = (double)s.top();
				s.pop();
				t1 = t1 / t2;
				break;
			}
			s.push(t1);
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << s.top();

	return 0;
}
