// https://www.codechef.com/MAY18B/problems/CHSIGN

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF 0x3f3f3f3f3f3f3f3fLL
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll a[n+1];
        for(ll i=1;i<=n;i++){
            cin>>a[i];
        }
 
        ll dp[n+1][2] = {0};
        ll path[n+1][2] = {0};
 
        dp[1][0] = a[1];
        dp[1][1] = - a[1];
 
        for(ll i=2;i<=n;i++){
            dp[i][0] = dp[i][1] = INF;
            dp[i][0] = dp[i-1][0] + a[i];
            path[i][0] = 0;
            if(a[i]>a[i-1] && dp[i][0] > dp[i-1][1] + a[i]){
                dp[i][0] = dp[i-1][1] + a[i];
                path[i][0] = 1;
            }
            if(a[i] < a[i-1]){
                dp[i][1] = dp[i-2][0] + a[i-1] - a[i];
                path[i][1] = 0;
                if(a[i-1] > a[i] + a[i-2] && dp[i][1] > dp[i-2][1] + a[i-1]-a[i]){
                    dp[i][1] = dp[i-2][1] + a[i-1]-a[i];
                    path[i][1] = 1;
                }
            }
        }
        ll now,nn = n;
 
        if(dp[n][0] > dp[n][1]){
            now = 1;
        }else {
            now = 0;
        }
 
        while(nn>0){
            if(now){
                a[nn] = -a[nn];
                now = path[nn][now];
                nn = nn-2;
            }else {
                now = path[nn][now];
                nn = nn-1;
            }
        }
 
        for(ll i=1;i<=n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
} 