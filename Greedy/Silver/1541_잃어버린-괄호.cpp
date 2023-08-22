#include<iostream>
#include<string>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);

	string str, num;
	int result = 0, flag = 0;

	cin >> str;

	for (int i = 0; i <= str.length(); i++) {
		if (str[i] == '-' || str[i] == '+' || i == str.length()) {
			if (flag) 
				result -= stoi(num);			
			else 
				result += stoi(num);
			num = "";
		}
		else 
			num += str[i];

		if (str[i] == '-') 
			flag = 1;		
	}

	cout << result;

	return 0;

}