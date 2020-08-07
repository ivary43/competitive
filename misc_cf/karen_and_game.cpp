#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,n) for(long long i=a;i<=n;i++)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n-1)
#define SYNC ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define ll long long int
#define vi vector<int>
#define mp make_pair<int>

int arr[150][150];
int n,m;

void sub_row(int row, int val) {
	for(int i=0;i<m;++i) {
		arr[row][i]-=val;
	}
}

void sub_col(int col, int val) {
	for(int i=0;i<n;++i) {
		arr[i][col]-=val;
	}
}

pair<int,int> max_col(int col) {
	int mn = INT_MAX;
	int mx = INT_MIN;

	for(int i=0;i<n;++i) {
		if(arr[i][col] < mn) {
			mn = arr[i][col];
		}
		if(arr[i][col] > mx) {
			mx = arr[i][col];
		}
	}

	pair<int,int> tmp = {mn,mx};
	return tmp;
}

pair<int,int> max_row(int row) {
	int mn = INT_MAX;
	int mx = INT_MIN;

	for(int i=0;i<m;++i) {
		if(arr[row][i] < mn) {
			mn = arr[row][i];
		}
		if(arr[row][i] > mx) {
			mx = arr[row][i];
		}
	}

	pair<int,int> tmp = {mn,mx};
	return tmp;
}

int main() {

	cin>>n>>m ;
	vector<int> mn_row(n) ;

	for(int i=0;i<n;++i) {
		int mn = INT_MAX ;
		for(int j=0;j<m;++j) {
			cin>>arr[i][j];
			if(arr[i][j]< mn) {
				mn = arr[i][j];
			}
		}

		mn_row[i] = mn;
	}


	vector<string> res;


	if(m<=n) {
		for(int i=0;i<n;++i) {
				if(mn_row[i]>0) {
					sub_row(i,mn_row[i]);
					for(int j=0;j<mn_row[i];++j) {
						res.push_back("row "+to_string(i+1));
					}
				}
			}


			for(int i=0;i<m;++i) {
				pair<int,int> temp = max_col(i);

				if(temp.first != temp.second) {
					cout<<-1<<"\n";
					return 0;
				}

				for(int j=0;j<temp.first;++j) {
					res.push_back("col "+to_string(i+1));
				}
			}
		
	} else {

		for(int i=0;i<m;++i) {
			pair<int,int> val = max_col(i);
			if(val.first > 0) {
				sub_col(i,val.first);

				for(int j=0;j<val.first;++j) {
					res.push_back("col "+to_string(i+1));
				}
			}
		}

		for(int i=0;i<n;++i) {
			pair<int,int> val = max_row(i);

			if(val.first != val.second) {
				cout<<-1<<"\n";
				return 0;

			}

			for(int j=0;j<val.first;++j) {
				res.push_back("row "+to_string(i+1));
			}

		}

	}
	
		cout<<res.size()<<"\n";

			for(string str:res) {
				cout<<str<<"\n";
		}		

	return 0;
}