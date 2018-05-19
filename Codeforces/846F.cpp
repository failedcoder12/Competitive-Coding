// http://codeforces.com/problemset/problem/846/F

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF 0x3f3f3f3f3f3f3f3fLL

ll dp[1000001];

int main(){
    ll n;
    cin>>n;
    ll a[n+1];
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    unordered_map<ll,ll> m;
    dp[1] = 1;
    m[a[1]] = 1;
    for(ll i=2;i<=n;i++){
        dp[i] = dp[i-1] + i;
        if(m.count(a[i])==0){
            m[a[i]] = i;
        }else {
            dp[i] -= m[a[i]];
            m[a[i]] = i;
        }
    }
    
    ll sum = 0;
    for(ll i=1;i<=n;i++){
        sum+=dp[i];
    }
    double ans;
    ans = (2*(sum-n) + n + 0.0)/(n*n*1.0);
    cout<<fixed<<setprecision(6)<<ans<<endl;
}