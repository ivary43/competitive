#include<bits/stdc++.h>
using namespace std;
int main() {

	int T;

	cin>>T;

	while(T--) {
		string s;
	cin>>s;

		int l=0 , r=0, u=0, d=0;
		int n = s.length();

		for(int i=0;i<n;++i) {
				if(s[i] == 'L') {
					l++;
				} else if(s[i] == 'R') {
					r++;
				} else if(s[i] == 'U') {
					u++;
				} else {
					d++;
				}
		}


		int l_ = min(l,r);
		int u_ = min(u,d);

		if(u_ == 0) {
			l_ = min(1, l_);
		}

		if(l_ == 0) {
			u_ = min(1, u_);
		}
		
		string res = "";

		for(int i=0;i<l_;++i) {
			res+="R";
		}

		for(int i=0;i<u_;++i) {
			res+="D";
		}

		for(int i=0;i<l_;++i) {
			res+="L";
		}

		for(int i=0;i<u_;++i) {
			res+="D";
		}

		cout<<res<<"\n";
	}
	

	return 0;
}