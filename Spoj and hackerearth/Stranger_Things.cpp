
// https://www.hackerearth.com/practice/math/combinatorics/inclusion-exclusion/practice-problems/algorithm/thl-cake1/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll countbits(ll n){
    ll count = 0;
    while(n>0){
        n = n & (n-1);
        count++;
    }
    return count;
}

ll gcd(ll a,ll b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}

ll lcm(ll a,ll b){
    ll g = gcd(a,b);
    return a*b/g;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>k;
        ll a[k];
        for(ll i=0;i<k;i++){
            cin>>a[i];
        }
        cin>>n;
        ll ans = 0;
        ll p = pow(2,k);
        for(ll i=1;i<p;i++){
            ll bits = countbits(i);
            ll marks = i;
            ll pos = 0;
            ll temp = 1;
            while(marks>0){
                if(marks&1)
                    temp = lcm(temp,a[pos]);
                pos++;
                marks = marks/2;
            }
            if(bits&1){
                ans += n/temp;
            }else {
                ans -= n/temp;
            }
        }
        cout<<ans<<endl;
    }
}
