#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main() {

	int N, num, cnt = 0;
	string str = "";
	stack<int> st;
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		while (cnt < num) {
			cnt++;
			st.push(cnt);
			str += "+\n";
		}
		if (st.top() != num) {
			str = "NO";
			break;
		}
		else {
			st.pop();
			str += "-\n";
		}		
	}
	
	cout << str;

	return 0;
}