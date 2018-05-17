// http://www.spoj.com/problems/FARIDA/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
int main(){
 
    ll tt;
    cin>>tt;
    for(ll t = 1;t<=tt;t++){
        ll n;
        cin>>n;
        ll a[n+1];
        for(ll i=1;i<=n;i++){
            cin>>a[i];
        }
 
        ll dp[n+1];
 
        dp[1] = a[1];
        dp[2] = max(a[2],dp[1]);
 
        for(ll i=3;i<=n;i++){
            dp[i] = max(dp[i-2]+a[i],dp[i-1]);
        }
        cout<<"Case "<<t<<": ";
        cout<<dp[n]<<endl;
    }
} 