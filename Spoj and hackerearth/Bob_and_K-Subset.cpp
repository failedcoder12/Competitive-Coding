// https://www.hackerearth.com/challenge/competitive/may-circuits-18/algorithm/bob-and-subset-23f0729c/

#include<bits/stdc++.h>
using namespace std;
#define ll unsigned int
#define INF 0x3f3f3f3f3f3f3f3fLL
using namespace std;
 
int main(){
    ll n,k;
    cin>>n>>k;
 
    ll check[2049];
    memset(check,k+1, sizeof(check));
 
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        check[x] = 1;
    }
    
    for(ll i=1;i<=2048;i++){
        if(check[i] > k ){
            continue;
        }
        for(ll k=1;k<=i;k++){
            ll y = (i|k);
            check[y] = min(check[y],check[i]+check[k]);
        }
    }
    
    ll count = 0;
    for(ll i=1;i<=2048;i++){
        if(check[i] <= k){
            count++;
        }
    }
    cout<<count<<endl;
}