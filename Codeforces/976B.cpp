// http://codeforces.com/contest/976/problem/B

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll n,m,k;
    cin>>n>>m>>k;

    if(k<n){
        cout<<k+1<<" "<<1<<endl;
        return 0;
    }


    if(m == 2){
        k = k-n+1;
        cout<<n-k+1<<" "<<2<<endl;
        return 0;
    }
    if(k == n){
        cout<<n<<" "<<2<<endl;
        return 0;
    }

    k = k-n+1;

    ll kk = k;

    ll c = (k)%(m-1);
    ll r = (k-1)/(m-1);
    // cout<<k<<" "<<r<<" "<<c<<endl;

    if((r)%2 == 0){
        if(c == 0){
            c = m-1;
        }
        cout<<n-r<<" "<<(c+1)<<endl;
    }else {
        if(c == 0){
            c = m-1;
        }
        cout<<n-r<<" "<<(m-c+1)<<endl;
    }
}