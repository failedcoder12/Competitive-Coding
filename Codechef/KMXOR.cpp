// https://www.codechef.com/COOK94B/problems/KMXOR

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF 0x3f3f3f3f3f3f3f3fLL
using namespace std;
 
ll max_xor(ll n,ll k){
    if(n == 1){
        return k;
    }
 
    ll res = 1;
    while(k){
        res = res*2;
        k = k/2;
    }
    return res;
}
 
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll xor_ = max_xor(n,k)-1;
 
        if(n == 1){
            cout<<k<<endl;
            continue;
        }
 
        if(k == 1){
            while(n){
                cout<<1<<" ";
                n--;
            }
            cout<<endl;
            continue;
        }
        if(k == 2){
            if(n%2 == 0){
                cout<<1<<" ";
                n = n-1;
            }
            while(n){
                cout<<2<<" ";
                n--;
            }
            cout<<endl;
            continue;
        }
 
        if(k == 3){
            if(n%2 == 0){
                cout<<1<<" ";
                n = n-1;
                while(n){
                    cout<<2<<" ";
                    n--;
                }
                cout<<endl;
                continue;
            }
            while(n){
                cout<<3<<" ";
                n--;
            }
            cout<<endl;
            continue;
        }
        if(n%2 == 0){
            ll w1 = (xor_ + 1)/2;
            ll w2 = xor_ - w1;
            cout<<w1<<" "<<w2<<" ";
            n = n-2;
            while(n){
                cout<<1<<" ";
                n--;
            }
            cout<<endl;
            continue;
        }
 
        if(n%2 == 1){
            ll w1 = (xor_ + 1)/2;
            ll w2 = (xor_ + 1)/4;
            ll w3 = xor_ - w1 - w2;
            cout<<w1<<" "<<w2<<" "<<w3<<" ";
            n = n-3;
            while(n){
                cout<<1<<endl;
                n--;
            }
            cout<<endl;
            continue;
        }
 
    }
}