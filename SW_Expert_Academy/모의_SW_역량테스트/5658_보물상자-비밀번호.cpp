#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
    
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int N, K, answer, idx = 0;
        string str;
        vector<int> v;
        vector<long long> st;
        cin >> N >> K >> str;
        int n = N / 4;
        int s = str.size();
        for(int i=0; i<s; i++){
        	if('0' <= str[i] && str[i] <= '9')
                v.push_back(str[i]-'0');
            else
                v.push_back(str[i]-'A'+10);
        }
        
        for(int i=0; i<s; i++){
            long long sum = 0;
            long long cal = pow(16, n-1);
            
            for(int j=0; j<n; j++){
            	if(i+j >= s)
                    sum += v[i+j-s] * cal;
                else
                    sum += v[i+j] * cal;
                cal /= 16;
            }
            st.push_back(sum);
        }
        sort(st.begin(), st.end(), greater<long long>());
	
        for(int i=0; i<K-1; i++){
        	int temp = idx;
            while(st[++temp] == st[idx]);
            idx = temp;
        }
        
		cout << "#" << test_case << " " << st[idx] << endl;
	}
	return 0;
}
