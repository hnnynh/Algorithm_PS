// 4n%에서 틀렸습니다 -> 로직은 문제없고 예외처리 문제?
// => 문자열이 끝났는데 stack에 데이터가 남아있는 경우 처리 -> 맞았습니다

#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main() {
	int result = 0, temp = 1;
	string str;
	stack<char> p;

	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			temp *= 2;
			p.push(str[i]);
		}
		else if (str[i] == '[') {
			temp *= 3;
			p.push(str[i]);
		}
		else if (str[i] == ')') {
			if (p.empty() || p.top() != '(') {
				result = 0;
				break;
			}
			if (str[i - 1] == '(')
				result += temp;	

			temp /= 2;
			p.pop();
		}
		else if (str[i] == ']') {
			if (p.empty() || p.top() != '[') {
				result = 0;
				break;
			}
			if (str[i - 1] == '[')
				result += temp;

			temp /= 3;
			p.pop();
		}
	}

	if (!p.empty())
		result = 0;

	cout << result;
	return 0;
}
