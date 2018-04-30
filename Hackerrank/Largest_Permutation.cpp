// https://www.hackerrank.com/contests/code-saga/challenges/largest-permutation

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){

    ll n,s;
    cin>>n>>s;

    ll a[n];
    ll b[n];
    map<ll,ll> m,m1;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        b[i] = a[i];
    }

    sort(b,b+n);
    for(ll i=0;i<n;i++){
        m[b[i]] = i;
        m1[i] = b[i];
    }
    ll x[n];
    for(ll i=0;i<n;i++){
        x[i] = m[a[i]];
    }

    ll pos[n];
    for(ll i=0;i<n;i++){
        pos[x[i]] = i;
    }

    for(ll i=0;i<n&&s;i++){
        if(x[i] == n-i-1){
            continue;
        }
        ll temp = pos[n-i-1];
        pos[x[i]] = pos[n-i-1];
        pos[n-i-1] = i;
        ll pp = x[temp];
        x[temp] = x[i];
        x[i] = pp;
        --s;
    }

    for(ll i=0;i<n;i++){
        cout<<m1[x[i]]<<" ";
    }
    cout<<endl;

}