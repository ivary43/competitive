#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> adj_l , bool isVisited[], int src) {
	if(!isVisited[src]) {
		isVisited[src] ;
		vector<int>:: iterator it ;

		for(it=adj_l[src].begin(),it!= adj_l[src].end();++it) {
				if(!isVisited[*it]) {
					dfs(adj_l, isVisited, *it);
				}
		}
	}

}

void bfs(vector<vector<int>> adj_l,int n) {
	bool isVisited[n];
	memset(false,isVisited, sizeof(isVisited));

	queue<int> qu ;

	qu.push_back(0);
	isVisited[0] = true;

	vector<int> :: iterator it ; 
	while(!qu.empty()) {
		int u = qu.front(); qu.pop();

		for(it=adj_l[u].begin(); it!=adj_l[u].end();++it) {
			if(!isVisited[*it]) qu.push_back(*it);
		}

	}

}




int main() {
	int n,m ;
	cin>>n>>m ;

	vector<vector<int>> vi[n];
	int x,y ;

	for(int i=0;i<m;++i) {
		vi[x].push_back(y) ;
		// comment out if UDG
		// vi[y].push_back(x) ;
	}

	bool isVisited[n];
	memset(false,isVisited, sizeof(isVisited));

	return 0;
}