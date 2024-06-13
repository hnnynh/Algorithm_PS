#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main() {
	
	int N, cal = 0, ans = 0;
	vector<string> P;
	set<string> s;
	map<string, int> score;
	string S;
	
	cin >> N >> S;
	
	for(int i=1; i<N; i++){
		for(int j=i+1; j<N; j++){			
			string first = S.substr(0, i);
			string second = S.substr(i, j - i);
			string third = S.substr(j, N - j);
			
			s.insert(first);
			s.insert(second);
			s.insert(third);
		}
	}
	
	for(string s : s) {
    P.push_back(s);
	}
	
	for(int i=0; i<P.size(); i++) 
		score[P[i]] = i+1;
	
	for(int i=0; i<N; i++){
		for(int j=i+1; j<N; j++){
			int a = score[S.substr(0, i)];
			int b = score[S.substr(i, j - i)];
			int c = score[S.substr(j, N - j)];
			ans = max(ans, a+b+c);
		}
	}

  cout << ans << endl;
  return 0;
}