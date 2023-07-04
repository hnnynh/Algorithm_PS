#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main() {
	int result = 0, flag = 0;
	string str;
	stack<int> p;

	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			flag = 1;
			p.push(flag);	
		}
		else {
			if (flag)
				result += p.size() - 1;
			else
				result++;
			flag = 0;
			p.pop();
		}
	}

	cout << result;

	return 0;
}
