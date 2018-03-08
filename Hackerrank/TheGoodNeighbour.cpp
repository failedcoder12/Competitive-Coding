// https://www.hackerrank.com/contests/nitk-cp-league-contest1/challenges/tgn
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
    ll n,m,q;
    cin>>n>>m>>q;
    float a[n+1] = {0};
    ll g[m+1];
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    for(ll j=1;j<=m;j++){
        cin>>g[j];
    }
    sort(a+1,a+n+1);

    float ans[m+1];
for(ll j=1;j<=m;j++){
    float mini = FLT_MAX;
    for(ll i=n;i>g[j];i--){
        mini = min(mini, a[i] / a[i-g[j]]);
    }
    ans[j] = mini;
}

    for(ll i=0;i<q;i++){
        float k;ll j;
        cin>>k>>j;
        if(ans[j] >= k){
            cout<<"yes"<<endl;
        }else {
            cout<<"no"<<endl;
        }
    }

}