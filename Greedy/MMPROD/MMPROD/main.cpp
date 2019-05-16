#include "/Users/manishkumar/Work/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long int modifiedMod(long int num) {
    if(num>=0) {
        return (1ll*num)%MOD;
    } else {
        long int temp = abs(num);
        temp%=MOD;
        temp=MOD - temp;
        return temp;
    }
}


int main() {
    
    int T;
    cin>>T;
    while(T--) {
        int n ,k ;
        cin>>n>>k ;
        int arr[n];
        int dup_arr[n];
        int no_pos = 0;
        int no_neg = 0;
        for(int i =0;i<n;++i) {
            cin>>arr[i];
            dup_arr[i]=abs(arr[i]);
            if(arr[i]>=0) {
                no_pos++;
            } else {
                no_neg++;
            }
        }
        
        
        
        sort(arr, arr+n);
        sort(dup_arr, dup_arr+n);
        int temp = (no_neg%2 == 0 )?no_neg:no_neg-1;
        if(k==1) {
            cout<<modifiedMod(max(arr[0], arr[n-1]))<<endl;
        } else if(no_pos + temp < k || no_pos == 0) {
            long int res =1 ;
            for(int i=0;i<k;++i) {
                res*=dup_arr[i];
                res = modifiedMod(res);
            }
            res*=-1;
            res = modifiedMod(res);
            cout<<res<<endl;
            
        } else {
            int l = 0 ;
            int r = n-1;
            long int res = 1 ;
            while(k>0) {
                if(l>r) {
                    break;
                }
                
                if(k == 1) {
                    res*=(max(arr[l], arr[r]));
                    res=modifiedMod(res);
                    k--;
                } else if( 1ll*arr[l]*arr[l+1] > 1ll*arr[r]*arr[r-1]) {
                    res*=((1ll*arr[l]*arr[l+1]));
                    res=modifiedMod(res);
                    l+=2;
                    k-=2;
                } else {
                    res*=(1ll*arr[r]*arr[r-1]);
                    res=modifiedMod(res);
                    r-=2;
                    k-=2;
                }
                
                
            }
            
            cout<<res<<endl;
        }
        
    }
    
    
    
    
    
    return 0;
}
