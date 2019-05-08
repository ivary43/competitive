#include "/Users/manishkumar/Work/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
int main () {
    string str ;
    cin>>str;
    stack<int> pos ;
    int n = (int)str.length();
    int pos_corr_open_bracket[n];
    int dp[n];
    memset(pos_corr_open_bracket, -2, n*sizeof(pos_corr_open_bracket[0]));
    memset(dp,-2,n*sizeof(dp[0]));
    int max_res = 0;
    int max_count = 1;
    for(int i=0;i<n;++i) {
        if(str[i]=='(') {
            pos.push(i);
        } else if(str[i]==')' && pos.empty()) {
            dp[i]=-1;
            pos_corr_open_bracket[i]=-1;
        } else {
            int top = pos.top();
            pos.pop();
            pos_corr_open_bracket[i]=top;
            
            if(top == 0 ) {
                dp[i]=(i-top)+1;
                if(dp[i]>max_res) {
                    max_res = dp[i];
                    max_count = 1 ;
                } else if(dp[i] == max_res) {
                    max_count++;
                }
            } else if(str[top-1] ==')' && pos_corr_open_bracket[top-1]!=-1) {
                dp[i]=(i-top+1)+dp[top-1];
                if(dp[i]>max_res) {
                    max_res = dp[i];
                    max_count = 1 ;
                } else if(dp[i] == max_res) {
                    max_count++;
                }
            } else if(str[top-1] =='(' || pos_corr_open_bracket[top-1]== -1) {
                dp[i] = (i-top+1);
                if(dp[i]>max_res) {
                    max_res = dp[i];
                    max_count = 1 ;
                } else if(dp[i] == max_res) {
                    max_count++;
                }
            }
        }
        
    }
    
    cout<<max_res<<" "<<max_count<<endl;
    
    return 0;
}
