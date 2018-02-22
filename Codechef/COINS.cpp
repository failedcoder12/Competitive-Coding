
//https://www.codechef.com/problems/COINS

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
map<ll,ll> dp;
ll coins(ll n){
    if(n<=2){
        return n;
    }
    if(dp[n])
        return dp[n];
    dp[n] = max(n,coins(n/2)+coins(n/3)+coins(n/4));
    return dp[n];
}

int main(){
    ll n;
    while(cin>>n){
    cout<<coins(n)<<endl;
    }
}