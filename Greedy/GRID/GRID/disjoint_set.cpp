#include<bits/stdc++.h>
using namespace std;


void findP(int parent[], int s1) {

	if(parent[s1] == -1) {
		return s1;
	} else {
		return findP(parent, parent[s1]);
	}
}

void union_set(int parent[], int s1 , int s2) {
		parent[s1] = s2;	
}

int main() {

	int n ,m ;
	cin>>n>>m ;


	int parent[n];

	memset(-1, parent, sizeof(parent))

	pair<int,int> pr;
	for(int i=0;i<m;++i) {
		cin>>pr[i].first>>pr[i].second;
	}

	for (pair<int,int> temp : pr) {
		int p1 = findP(parent, temp.first);
		int p2 = findP(parent, temp.second);

		if(p1 != p2) {
			union_set(parent, p1,p2);
		}
	}

	for(int i=0;i<n;++i) {
		cout<<i<<"-->"parent[i];
	}
	
	return 0;
}