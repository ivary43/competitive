#include<bits/stdc++.h>
using namespace std;

int main() {

	int n, m;
	string s ;
	unordered_set<char> st;

	cin>>s;

	char ch;

	for(int i=0;i<m;++i) {
		cin>>ch;
		st.insert(ch);
	}

	long long int res = 0 ;

	long long int cnt = 0;

	for(int i=0;i<n;++i) {
		if(st.find(s[i])==st.end()) {
			cnt++;
		} else{
			res+=((cnt*(cnt+1))>>1);
			cnt =0 ;
		}
	}

	cout<<res<<"\n";
	return 0;
}