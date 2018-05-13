#include "/Users/manishkumar/Downloads/Header/stdc++.h"
//#include<bits/stdc++.h>
using namespace std ;
#define pb push_back
#define INF 1e8
#define SYNC() ios_base::sync_with_stdio(false); cin.tie(NULL);

int min (int a ,int b ) {
    return a<b?a:b;
}

int matrixMultiplication( vector<pair<int,int>> matrixs ) {
    
    SYNC()
    int numberOfMatrix = (int)matrixs.size();
    int matrix[numberOfMatrix][numberOfMatrix];
    
    //making all diagonal elements zero
    for(int i =0 ;i<numberOfMatrix;++i ) {
        matrix[i][i] =0 ;
    }
    
    for(int L =2 ;L<=numberOfMatrix ;++L) {
        for( int i =0 ;i<numberOfMatrix ;++i ) {
            int j=i+L-1;
            matrix[i][j]= INT_MAX;
            
            for(int k =i ;k<j ;++k ) {
                matrix[i][j]= min(matrix[i][j], matrix[i][k]+matrix[k+1][j] + matrixs[i].first*matrixs[j].second*matrixs[k].second ) ;
            }
        }
    }
    
    return matrix[0][numberOfMatrix-1];
    
}

int main () {
    int n ;
    cin>>n;
    vector<pair<int,int>>  matrixs;
    
    int dim[n];
    for(int i =0 ;i<n;++i ) {
        cin>>dim[i];
    }
    
    for(int i=0 ;i<n-1;++i) {
        matrixs.push_back(make_pair(dim[i], dim[i+1]));
    }
    
    cout<<matrixMultiplication(matrixs)<<endl;
    
    return 0 ;
}


