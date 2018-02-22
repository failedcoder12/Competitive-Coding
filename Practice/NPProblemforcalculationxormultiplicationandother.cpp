
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll t;
    cin>>t;
    while(t--){
    ll n,x;
    cin>>n>>x;
    ll a[n+1] = {0};
    ll max_ele = -1;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>max_ele){
            max_ele = a[i];
        }
    }
    ll combination[21][1001];
    memset(combination, 0, 21*1001*sizeof(combination[0][0]));
    ll module = (1 << (ll)(log2(max_ele) + 1) );
    for(ll i=1;i<=n;i++){
        for(ll m=0;m<module;m++){
            combination[i][m] += combination[i-1][m];
            ll xor_with_m = (a[i]^m);
            combination[i][xor_with_m] += combination[i-1][m];
        }
        combination[i][a[i]]++;
    }
    
    cout<<combination[n][x]<<endl;
    }
}