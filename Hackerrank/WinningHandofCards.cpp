//https://www.hackerrank.com/contests/rookierank-4/challenges/winning-hand-of-cards
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll combination[31][1000001];

int main(){
    ll n,module,x;
    cin>>n>>module>>x;
    ll a[n+1] = {0};
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    
    for(ll i=1;i<=n;i++){
        for(ll m=0;m<module;m++){
            combination[i][m] += combination[i-1][m];
            ll product_with_m = (a[i]*m)%module;
            combination[i][product_with_m] += combination[i-1][m];
        }
        combination[i][a[i]%module]++;
    }
    
    cout<<combination[n][x]<<endl;
    
}