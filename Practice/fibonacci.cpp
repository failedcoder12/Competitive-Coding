

// http://codeforces.com/blog/entry/14516

#include<bits/stdc++.h>
using namespace std;

#define M 1000000007
#define ll long long int

map<ll,ll> F;

ll f(ll n){
    if(F.count(n)) return F[n];
    ll k = n/2;
    if(n%2==0){
        return F[n] = f(k)*f(k) + f(k-1)*f(k-1) % M;
    }else {
        return F[n] = f(k)*f(k+1) + f(k-1)*f(k);
    }
}

int main(){
    F[0] = 1;
    F[1] = 1;
    ll n;
    cin>>n;
    if(n==0)
        cout<<1<<endl;
    else
        cout<<f(n-1)<<endl;
}