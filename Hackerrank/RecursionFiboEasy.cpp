   // https://www.hackerrank.com/challenges/ctci-fibonacci-numbers/problem
    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long int
    map<ll,ll> m;

    ll nth(ll x){
        if(m.count(x)){
            return m[x];
        }
        ll k = x/2;
        m[2*k] = nth(k)*nth(k) + nth(k-1)*nth(k-1);
        m[2*k+1] = nth(k)*nth(k+1) + nth(k-1)*nth(k);
        return m[x];
    }

    int main() {

        ll n;
        cin>>n;
        m[-1] = 0;
        m[0] = 1;
        m[1] = 1;
        
        cout<<nth(n-1)<<endl;

    }