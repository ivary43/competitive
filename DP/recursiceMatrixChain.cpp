#include "/Users/manishkumar/Downloads/Header/stdc++.h"
//#include<bits/stdc++.h>
using namespace std ;
#define pb push_back
#define INF 1e5

int min (int a ,int b ,int c ) {
    return min(min(a,b),min(b,c));
}

int min (int a ,int b ) {
    return a<b?a:b;
}

int matrixMultiply( vector<int> p, int i,int j) {
    if( i == j ) {
        return 0;
    }
    
    else {
        int val = INF;
        for( int m =i ;m<j;m++) {
            val = min(val,matrixMultiply(p, i,m)+matrixMultiply(p, m+1, j)+p[i-1]*p[j]*p[m]);
        }
        return val ;
    }
}

int main () {
    int n, dummy;
    cin>>n;
    vector<int> mSize;
    for( int i=0 ;i<n;++i ) {
        cin>>dummy;
        mSize.pb(dummy);
    }
    int value = matrixMultiply(mSize, 1,(int) mSize.size() -1);
    
    cout<<value<<endl;
    return 0;
}

