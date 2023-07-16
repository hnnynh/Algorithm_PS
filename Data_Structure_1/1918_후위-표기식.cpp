// if(priority(stack.top()) >= priority(str[i])) 꺼내고 str[i] push
// else str[i]push

#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main() {

	string str;
	stack<char> st;

	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		if ('A' <= str[i] && str[i] <= 'Z') {
			cout << str[i];
		}
		else if (str[i] == '(') {
			st.push('(');
		}
		else if (str[i] == ')') {
			while (st.top() != '(') {
				cout << st.top();
				st.pop();
			}
			st.pop();
		}
		else if (str[i] == '*' || str[i] == '/') {
			while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
				cout << st.top();
				st.pop();
			}
			st.push(str[i]);
		}
		else if (str[i] == '+' || str[i] == '-') {
			while (!st.empty() && (st.top() == '*' || st.top() == '/' || st.top() == '+' || st.top() == '-')) {
				cout << st.top();
				st.pop();
			}
			st.push(str[i]);
		}
		
	}
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}

	return 0;
}